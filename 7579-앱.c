#include <stdio.h>
#include <string.h>

static inline int max(int a, int b) { return a > b ? a : b; }

int memory[101];
int cost[101];
int dp[10001];

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

    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; ++i) {
        for (int j = 10000; j >= 0; --j) {
            if (j - cost[i] >= 0) {
                dp[j] = max(dp[j], dp[j - cost[i]] + memory[i]);
            }
        }
    }

    for (int j = 0; j <= 10000; ++j) {
        if (dp[j] >= m) {
            printf("%d\n", j);
            break;
        }
    }
}
