#include <stdio.h>

typedef struct Stack {
    int size;
    int stack[4];
} Stack;
static inline void push(int e, Stack *s) { s->stack[s->size++] = e; }
static inline void pop(Stack *s) { --s->size; }
static inline int top(const Stack *s) { return s->stack[s->size - 1]; }
static inline int empty(const Stack *s) { return !s->size; }

Stack opstack;
Stack numstack;

char buf[8];
int mtoi()
{
    int n = 0;
    for (const char *c = buf; *c; ++c) {
        switch (*c) {
        case '.':
            ++n;
            break;
        case '-':
            n += 5;
            break;
        case ':':
            n += 2;
            break;
        case '=':
            n += 10;
            break;
        }
    }
    return n;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    n = (n << 1) + 1;

    while (n--) {
        scanf("%s", buf);

        if (buf[0] == '+') {
            while (!empty(&opstack)) {
                const char op = top(&opstack);
                pop(&opstack);

                const int rhs = top(&numstack);
                pop(&numstack);
                const int lhs = top(&numstack);
                pop(&numstack);

                switch (op) {
                case '+':
                    push(lhs + rhs, &numstack);
                    break;
                case '*':
                    push(lhs * rhs, &numstack);
                    break;
                }
            }
            push('+', &opstack);
        } else if (buf[0] == '*') {
            while (!empty(&opstack)) {
                const char op = top(&opstack);
                if (op == '+') {
                    break;
                }
                pop(&opstack);

                const int rhs = top(&numstack);
                pop(&numstack);
                const int lhs = top(&numstack);
                pop(&numstack);
                push(lhs * rhs, &numstack);
            }
            push('*', &opstack);
        } else {
            push(mtoi(), &numstack);
        }
    }

    while (!empty(&opstack)) {
        const char op = top(&opstack);
        pop(&opstack);

        const int rhs = top(&numstack);
        pop(&numstack);
        const int lhs = top(&numstack);
        pop(&numstack);

        switch (op) {
        case '+':
            push(lhs + rhs, &numstack);
            break;
        case '*':
            push(lhs * rhs, &numstack);
            break;
        }
    }

    printf("%d\n", top(&numstack));
}
