#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	int a = 1;
	int b = 0;
	for (int i = 0; i < n; ++i) {
		int tmp = b;
		b = a;
		a = (a + tmp) % 15746;
	}
	printf("%d\n", a);

	return 0;
}
