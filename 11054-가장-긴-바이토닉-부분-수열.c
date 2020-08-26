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

	// dec[i]: the length of the longest subseq that starts at arr[i]
	int dec[MAX];
	for (int i = n - 1; i >= 0; --i) {
		int curr = 0;
		for (int j = n - 1; j > i; --j) {
			if (arr[j] < arr[i]) {
				curr = max(curr, dec[j]);
			}
		}
		dec[i] = curr + 1;
	}

	int max_bin_len = 0;
	for (int i = 0; i < n; ++i) {
		max_bin_len = max(max_bin_len, inc[i] + dec[i] - 1);
	}
	printf("%d\n", max_bin_len);

	return 0;
}
