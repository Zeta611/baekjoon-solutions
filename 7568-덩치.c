#define MAX_N 50
#include <stdio.h>

int main(void)
{
	int weight[MAX_N];
	int height[MAX_N];

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &weight[i], &height[i]);
	}

	for (int i = 0; i < n; ++i) {
		int order = 1;
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}
			if (weight[j] > weight[i] && height[j] > height[i]) {
				++order;
			}
		}

		printf("%d", order);
		if (i < n - 1) {
			printf(" ");
		}
	}

	return 0;
}
