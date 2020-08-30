#include <stdlib.h>
#include <stdio.h>

static inline int min(int a, int b)
{
	return a < b ? a : b;
}

int try(int lo, int hi, int n, int k)
{
	if (lo == hi) {
		return lo;
	}

	long mid = (lo + hi) / 2;
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		// Count the numbers smaller than or equal to mid in the i-th
		// line.
		cnt += min(mid / i, n);
	}

	if (cnt < k) {
		return try(mid + 1, hi, n, k);
	} else {
		return try(lo, mid, n, k);
	}
}

int main(void)
{
	int n, k;
	scanf("%d\n%d", &n, &k);
	// k-th number is always smaller than or equal to k itself, e.g.,
	// 1 2 3 4 5 6 7 8 9
	// 1 2 3 2 4 6 3 6 9
	printf("%d\n", try(1, k, n, k));
	return 0;
}
