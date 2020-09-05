#include <stdio.h>

int main(void)
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int ret = 1;
	while (b) {
		if (b % 2) {
			ret = (int)((long)ret * a % c);
			--b;
		} else {
			a = (int)((long)a * a % c);
			b /= 2;
		}
	}
	printf("%d\n", ret);
	return 0;
}
