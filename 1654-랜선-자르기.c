#include <stdlib.h>
#include <stdio.h>

int try(long lo, long hi, int *lines, int k, int n)
{
	if (hi - lo == 1) {
		return lo;
	}

	long mid = (lo + hi) / 2;
	int cnt = 0;
	for (int i = 0; i < k; ++i) {
		cnt += lines[i] / mid;
	}

	if (cnt < n) {
		return try(lo, mid, lines, k, n);
	} else {
		return try(mid, hi, lines, k, n);
	}
}

int main(void)
{
	int k, n;
	scanf("%d %d", &k, &n);

	int *lines = malloc(k * sizeof(int));
	for (int i = 0; i < k; ++i) {
		scanf("%d", &lines[i]);
	}

	printf("%d\n", try(0, (long)1 << 31, lines, k, n));

	free(lines);
	return 0;
}
