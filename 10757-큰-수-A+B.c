#include <ctype.h>
#include <stdio.h>
#define MAXDIG 10000
#define CHAR2DIG(c) ((c) - '0')
#define DIG2CHAR(d) ((d) + '0')
// -1 represents an end-of-number marker.
#define EON -1

typedef char dig;

// Returns the length of the input number.
size_t getnum(dig *n)
{
	// We want the least significant digit in the index 0.
	dig rev[MAXDIG + 1];
	size_t len = 0;
	int c;
	while (isdigit(c = getchar())) {
		rev[len++] = CHAR2DIG(c);
	}

	// Put contents of `rev` into `n` in a reverse order.
	for (size_t i = len; i; --i) {
		*n++ = rev[i - 1];
	}
	*n = EON;
	return len;
}

void putnum(dig *n, size_t len)
{
	for (size_t i = len; i; --i) {
		putchar(DIG2CHAR(n[i - 1]));
	}
}

// Returns the length of the sum.
size_t addnum(dig *a, dig *b, dig *sum)
{
	size_t len = 0;
	dig carry = 0;
	while (carry || *a != EON || *b != EON) {
		dig s = (*a != EON ? *a++ : 0) + (*b != EON ? *b++ : 0) + carry;
		*sum++ = s % 10;
		carry = s / 10;
		++len;
	}
	*sum = EON;
	return len;
}

int main(void)
{
	dig a[MAXDIG + 1], b[MAXDIG + 1], sum[MAXDIG + 2];
	size_t len;
	getnum(a);
	getnum(b);
	len = addnum(a, b, sum);
	putnum(sum, len);
	putchar('\n');
}
