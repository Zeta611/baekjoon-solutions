#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#define STK_CAP 500
#define QUE_CAP 500

static const enum {
	LASSOC,
	RASSOC,
	NASSOC
} SYM_ASSOC[] = {['|'] = LASSOC, ['&'] = LASSOC, ['^'] = LASSOC,
		 ['~'] = RASSOC, ['('] = NASSOC, [')'] = NASSOC};

static const int SYM_PREC[] = {
    ['|'] = 0, ['&'] = 2, ['^'] = 1, ['~'] = 3, ['('] = -1, [')'] = -1};

static inline int op_cmp(unsigned char a, unsigned char b)
{
	// '-' is fine here--`SYM_PREC` stores only small integers.
	return SYM_PREC[a] - SYM_PREC[b];
}

static inline bool isop(int c)
{
	return c == '|' || c == '&' || c == '^' || c == '~';
}

static inline bool ispar(int c) { return c == '(' || c == ')'; }

// Reads characters from stdin and returns a recognized token.
// Only one character is read, with an exception to the leading white spaces.
int gettok()
{
	int ch;
	do {
		ch = getchar();
	} while (isspace(ch));
	return ch;
}

typedef struct Stack {
	char *top;
	char container[STK_CAP];
	size_t size;
} Stack;

bool push_s(char val, Stack *s)
{
	if (s->size == STK_CAP) { // overflow
		return false;
	}
	++s->size;
	if (!s->top) { // empty
		s->top = s->container;
		*s->top = val;
	} else {
		*++s->top = val;
	}
	return true;
}

bool pop_s(Stack *s)
{
	if (!s->size) { // underflow
		return false;
	}
	if (s->size == 1) {
		s->top = NULL;
	} else {
		--s->top;
	}
	--s->size;
	return true;
}

typedef struct Queue {
	char *front;
	char *back;
	char container[QUE_CAP];
	size_t size;
} Queue;

bool push_q(char val, Queue *q)
{
	if (q->size == QUE_CAP) { // overflow
		return false;
	}
	++q->size;
	if (!q->back) { // empty
		q->front = q->back = q->container;
		*q->back = val;
	} else if (q->back == q->container + QUE_CAP - 1) {
		// The end of the underlying container is reached.
		q->back = q->container;
		*q->back = val;
	} else {
		*++q->back = val;
	}
	return true;
}

bool pop_q(Queue *q)
{
	if (!q->size) { // underflow
		return false;
	}
	if (q->size == 1) {
		q->front = q->back = NULL;
	} else if (q->front == q->container + QUE_CAP - 1) {
		// The end of the underlying container is reached.
		q->front = q->container;
	} else {
		++q->front;
	}
	--q->size;
	return true;
}

// Peak the next token and checks if `this` is the last token in the current
// expression.
bool end_exp(char this)
{
	if (this == ')' || isalpha(this)) {
		int next = gettok();
		if (next == EOF) {
			return true;
		} else if (isalpha(next)) { // VAR
			ungetc(next, stdin);
			return true;
		} else { // OP
			ungetc(next, stdin);
			return next == '~' || next == '(';
		}
	}
	return false;
}

// The difference between this and the original shunting-yard algorithm is that
// it peeks ahead one token to check if the read token belongs to the next
// expression using `end_exp`.
// Returns a bitmask representing a usage of variables 'a'-'z'. 'a' is the LSB.
uint32_t shunting_yard(Queue *que)
{
	uint32_t vmask = 0u;
	Stack stk = {0};
	int c;
	bool in_exp = true;
	do {
		c = getchar();
		if (c == EOF || c == '\n') {
			break;
		}
		ungetc(c, stdin);

		int tok = gettok();
		if (end_exp(tok)) { // Peak the next token.
			in_exp = false;
		}

		if (tok == EOF) {
			return 0u;
		} else if (isalpha(tok)) { // VAR
			// Turn on the bit for the variable.
			vmask |= 1u << (tok - 'a');
			push_q(tok, que);
		} else { // OP
			if (tok == '(') {
				push_s(tok, &stk);
			} else if (tok == ')') {
				while (stk.size && *stk.top != '(') {
					push_q(*stk.top, que);
					pop_s(&stk);
				}
				pop_s(&stk);
			} else {
				while (stk.size && *stk.top != '(' &&
				       *stk.top != ')') {
					char c = *stk.top;
					int cmp = op_cmp(tok, c);
					if (cmp < 0 ||
					    (cmp == 0 &&
					     SYM_ASSOC[c] == LASSOC)) {
						push_q(c, que);
						pop_s(&stk);
					} else {
						break;
					}
				}
				push_s(tok, &stk);
			}
		}
	} while (in_exp);

	while (stk.size) {
		char c = *stk.top;
		if (c == '(') {
			printf("MALFORMED EQ\n");
			return 0ul;
		}
		push_q(c, que);
		pop_s(&stk);
	}
	return vmask;
}

// Subset of `set` according to `sel`. For example:
// subset(0b0101110, 0b1111) == 0b0101110
// subset(0b0101110, 0b1011) == 0b0100110
// subset(0b0101110, 0b1000) == 0b0100000
// subset(0b0101110, 0b0101) == 0b0001010
// subset(0b0101110, 0b0000) == 0b0100000
uint32_t subset(uint32_t set, uint32_t sel)
{
	uint32_t sub = 0u;
	while (set) {
		sub |= (set & -set) * (sel & 1u);
		sel >>= 1;
		set &= set - 1u; // Turn off the rightmost 1bit of `set`.
	}
	return sub;
}

// Evaluate the RPN in `que` with variables in `vmask`.
bool eval(Queue *que, uint32_t vmask)
{
	Stack stk = {0};
	size_t qsize = que->size;
	while (qsize--) {
		bool val;
		char front = *que->front;
		bool loperand, roperand;

		if (isalpha(front)) { // VAR
			val = (vmask >> (front - 'a')) & 1u;
			push_s(val, &stk);
		} else { // OP
			roperand = *stk.top;
			pop_s(&stk);
			if (front == '~') {
				push_s(!roperand, &stk);
			} else { // Other symbols are binary operators.
				loperand = *stk.top;
				pop_s(&stk);
				switch (front) {
				case '|':
					push_s(loperand || roperand, &stk);
					break;
				case '&':
					push_s(loperand && roperand, &stk);
					break;
				case '^':
					push_s(loperand != roperand, &stk);
					break;
				default: // should no be reached
					break;
				}
			}
		}
		// We need to preserve `que` for other `eval` calls.
		push_q(front, que);
		pop_q(que);
	}
	return *stk.top;
}

// Count 1's in `x`.
int popcount(uint32_t x)
{
	// Divide-and-conquer
	x -= (x >> 1) & 0x55555555u;
	x = (x & 0x33333333u) + ((x >> 2) & 0x33333333u);
	x = (x + (x >> 4)) & 0x0F0F0F0Fu;
	x += x >> 8;
	x += x >> 16;
	return x & 0x0000003Fu;
}

int main(void)
{
	// `q1` and `q2` contain RPNs of the input.
	Queue q1 = {0};
	Queue q2 = {0};
	int n;
	scanf("%d\n", &n);
	for (int i = 1; i <= n; ++i) {
		// `vmask` represents variables used in the two expressions.
		uint32_t vmask = shunting_yard(&q1) | shunting_yard(&q2);
		// The number of variables in the first and the second
		// expressions. This is guaranteed to be less than or equal to
		// 10.
		int vcnt = popcount(vmask);
		bool same = true;
		for (uint32_t sel = 0u; sel < (1u << vcnt); ++sel) {
			uint32_t sub = subset(vmask, sel);
			if (eval(&q1, sub) != eval(&q2, sub)) {
				same = false;
				break;
			}
		}
		printf("Data set %d: %s\n", i,
		       same ? "Equivalent" : "Different");
		q1 = (Queue){0};
		q2 = (Queue){0};
	}
}
