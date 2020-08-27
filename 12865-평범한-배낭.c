#define N_MAX 101
#define K_MAX 100001
#include <stdio.h>
#include <stdlib.h>

static inline int max(int a, int b)
{
	return a > b ? a : b;
}

static inline int get(int *opt, int i, int w)
{
	return opt[i * K_MAX + w];
}

static inline void set(int *opt, int i, int w, int v)
{
	opt[i * K_MAX + w] = v;
}

int main(void)
{
	int n, k;
	scanf("%d %d", &n, &k);

	int weight[N_MAX], value[N_MAX];
	for (int i = 1; i <= n; ++i) {
		scanf("%d %d", &weight[i], &value[i]);
	}

	int *opt = calloc(N_MAX * K_MAX, sizeof(int));
	for (int i = 1; i <= n; ++i) {
		for (int w = 1; w <= k; ++w) {
			int v = get(opt, i - 1, w);
			int wi = weight[i];
			int vi = value[i];
			if (wi <= w) {
				v = max(v, get(opt, i - 1, w - wi) + vi);
			}
			set(opt, i, w, v);
		}
	}

	printf("%d\n", get(opt, n, k));
	free(opt);

	return 0;
}
