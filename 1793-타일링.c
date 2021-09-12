#include <stdio.h>
#include <string.h>

#define MODULUS 100000000

void calc(const int *n1, const int *n2, int *m)
{
    for (int i = 0; n1[i] >= 0 || n2[i] >= 0; ++i) {
        if (n1[i] >= 0 && n2[i] >= 0) {
            m[i] = n1[i] + 2 * n2[i];
        } else if (n1[i] >= 0) {
            m[i] = n1[i];
        } else {
            m[i] = 2 * n2[i];
        }
    }
}

void carry(int *m)
{
    for (int i = 0; m[i] >= 0; ++i) {
        if (m[i] >= MODULUS) {
            if (m[i + 1] > 0) {
                m[i + 1] += m[i] / MODULUS;
            } else {
                m[i + 1] = m[i] / MODULUS;
            }
            m[i] %= MODULUS;
        }
    }
}

void putnum(const int *m)
{
    int len = 0;
    while (m[len] >= 0) {
        ++len;
    }
    printf("%d", m[len - 1]);
    for (int i = len - 2; i >= 0; --i) {
        printf("%08d", m[i]);
    }
    putchar('\n');
}

int dp[251][11];

int main(void)
{
    memset(dp, -1, sizeof dp);
    dp[0][0] = dp[1][0] = 1;
    for (int i = 2; i <= 250; ++i) {
        calc(dp[i - 1], dp[i - 2], dp[i]);
        carry(dp[i]);
    }

    int n;
    while ((n = getchar()) != EOF) {
        ungetc(n, stdin);
        scanf("%d\n", &n);
        putnum(dp[n]);
    }
}
