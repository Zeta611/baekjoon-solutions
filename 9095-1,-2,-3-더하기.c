#include <stdio.h>

int dp[11] = {1, 1, 2};
int main(void)
{
    for (int i = 3; i < 11; ++i) {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
}
