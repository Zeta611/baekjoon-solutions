#define MAX 50
#include <stdio.h>

static inline int min(int a, int b) {
	return a < b ? a : b;
}

int color_cnt(char board[MAX][MAX], int width, int height, int x, int y)
{
	int cnt = 0;
	for (int i = x; i < x + 8; ++i) {
		for (int j = y; j < y + 8; ++j) {
			cnt += (board[j][i] == 'B') ^ ((i + j) % 2);
		}
	}
	return min(cnt, 64 - cnt);
}

int main(void)
{
	char board[MAX][MAX];

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i) {
		scanf("%s", board[i]);
	}

	int result = MAX * MAX;
	for (int x = 0; x <= m - 8; ++x) {
		for (int y = 0; y <= n - 8; ++y) {
			result = min(result, color_cnt(board, m, n, x, y));
		}
	}
	printf("%d\n", result);

	return 0;
}
