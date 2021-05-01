#include <stdio.h>
#include <tgmath.h>

enum Color {
	BLACK,
	BROWN,
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	VIOLET,
	GREY,
	WHITE
};

static inline long long prodval(enum Color col) { return pow(10, col); }

enum Color str2col(const char *s)
{
	switch (s[0]) {
	case 'b':
		return s[1] == 'l' ? s[2] == 'a' ? BLACK : BLUE : BROWN;
		break;
	case 'r':
		return RED;
		break;
	case 'o':
		return ORANGE;
		break;
	case 'y':
		return YELLOW;
		break;
	case 'g':
		return s[3] == 'e' ? GREEN : GREY;
		break;
	case 'v':
		return VIOLET;
		break;
	case 'w':
		return WHITE;
		break;
	default:
		return BLACK;
		break;
	}
}

long long calc(enum Color c1, enum Color c2, enum Color c3)
{
	return (c1 * 10 + c2) * prodval(c3);
}

int main(void)
{
	char cs1[10], cs2[10], cs3[10];
	scanf("%s\n%s\n%s", cs1, cs2, cs3);
	enum Color c1 = str2col(cs1);
	enum Color c2 = str2col(cs2);
	enum Color c3 = str2col(cs3);
	printf("%lld\n", calc(c1, c2, c3));
	return 0;
}
