#include <stdlib.h>
#include <stdio.h>

int try(int lo, int hi, int *woods, int n, int m)
{
	if (hi - lo == 1) {
		return lo;
	}

	long mid = (lo + hi) / 2;
	long cnt = 0;
	for (int i = 0; i < n; ++i) {
		long length = woods[i] - mid;
		if (length > 0) {
			cnt += length;
		}
	}

	if (cnt < m) {
		return try(lo, mid, woods, n, m);
	} else {
		return try(mid, hi, woods, n, m);
	}
}

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	int *woods = malloc(n * sizeof(int));
	for (int i = 0; i < n; ++i) {
		scanf("%d", &woods[i]);
	}

	printf("%d\n", try(0, 1000000001, woods, n, m));

	free(woods);
	return 0;
}
