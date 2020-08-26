#define POS 500
#define MAX 100
#include <stdio.h>

static inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	int lines[POS] = {0};
	for (int i = 0; i < n; ++i) {
		int idx, val;
		scanf("%d %d", &idx, &val);
		lines[idx - 1] = val;
	}

	int arr[MAX];
	int arr_i = 0;
	for (int i = 0; i < POS; ++i) {
		if (lines[i] != 0) {
			arr[arr_i++] = lines[i];
		}
	}

	// inc[i]: the length of the longest subseq that ends at arr[i]
	int inc[MAX];
	for (int i = 0; i < n; ++i) {
		int curr = 0;
		for (int j = 0; j < i; ++j) {
			if (arr[j] < arr[i]) {
				curr = max(curr, inc[j]);
			}
		}
		inc[i] = curr + 1;
	}

	int max_inc_len = 0;
	for (int i = 0; i < n; ++i) {
		max_inc_len = max(max_inc_len, inc[i]);
	}
	printf("%d\n", n - max_inc_len);

	return 0;
}
