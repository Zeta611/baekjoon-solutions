#include <limits.h>
#include <stdio.h>
#include <string.h>

#define INF (INT_MAX - 10000)

static inline int min(int a, int b) { return a < b ? a : b; }

int memory[101];
int cost[101];
int dp[2][10000001];

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        scanf("%d", &memory[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &cost[i]);
    }

    for (int j = 0; j <= m; ++j) {
        dp[0][j] = INF;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            if (j - memory[i] <= 0) {
                dp[1][j] = min(dp[0][j], cost[i]);
            } else {
                dp[1][j] = min(dp[0][j], dp[0][j - memory[i]] + cost[i]);
            }
        }
        memcpy(dp[0], dp[1], sizeof dp[1]);
    }
    printf("%d\n", dp[0][m]);
}
