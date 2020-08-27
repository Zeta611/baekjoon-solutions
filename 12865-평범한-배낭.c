#define N_MAX 101
#define K_MAX 100001
#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	int *opt = malloc(N_MAX * K_MAX * sizeof(int));
	opt[0] = 0;
	for (int i = 1; i <= n; ++i) {
		int wi, vi;
		scanf("%d %d", &wi, &vi);

		for (int w = k; w >= 1; --w) {
			int v = opt[w];
			opt[w] = wi > w ? v : max(v, opt[w - wi] + vi);
		}
	}

	printf("%d\n", opt[k]);
	free(opt);

	return 0;
}
