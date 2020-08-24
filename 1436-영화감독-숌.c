#include <stdbool.h>
#include <stdio.h>

bool has_666(long m)
{
	for (; m >= 666; m /= 10) {
		if (m % 1000 == 666) {
			return true;
		}
	}
	return false;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	long m = 665;
	int cnt = 0;
	while (cnt < n) {
		if (has_666(++m)) {
			++cnt;
		}
	}
	printf("%ld\n", m);

	return 0;
}
