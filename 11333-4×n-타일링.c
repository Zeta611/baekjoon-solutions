#include <stdio.h>
#define MODULUS 1000000007
#define SIZE (10000 / 3 + 1)

long long dp[SIZE] = {1, 3, 13};
int main(void)
{
    for (int i = 3; i < SIZE; ++i) {
        dp[i] = (5 * dp[i - 1] - 3 * dp[i - 2] + dp[i - 3]) % MODULUS;
        if (dp[i] < 0) {
            dp[i] += MODULUS;
        }
    }

    int n;
    scanf("%d", &n);
    while (n--) {
        int k;
        scanf("%d", &k);
        if (k % 3) {
            puts("0");
        } else {
            printf("%lld\n", dp[k / 3]);
        }
    }
}
