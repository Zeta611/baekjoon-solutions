#define MAX 1000
#include <stdio.h>

static inline int max(int a, int b)
{
	return a > b ? a : b;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	int arr[MAX];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
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
	printf("%d\n", max_inc_len);

	return 0;
}
