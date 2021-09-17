#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_K 15
#define MAX_M ((MAX_K) * ((MAX_K) + 1) / 2)
#define MAX_DIFF                                                               \
    ((MAX_K) * ((MAX_K) + 1) / 2 * (MAX_K) -                                   \
     (MAX_K) * ((MAX_K) + 1) * (2 * (MAX_K) + 1) / 6)
#define PAT_CNT(K) (((K) * ((K) + 1) + ((K) + 1) / 2) / 2)

int pat_cnt;
int patterns[PAT_CNT(MAX_K) + 1][4];
char dp[PAT_CNT(MAX_K) + 1][MAX_M + 1][2 * MAX_DIFF + 1];

bool tile(int p, int m, int d)
{
    if (m < 0) {
        return false;
    }
    if (m == 0) {
        return d == 0;
    }
    if (p <= 0) {
        return false;
    }

    char *val = &dp[p][m][d + MAX_DIFF];
    if (*val != -1) {
        return *val;
    }

    if (tile(p - 1, m, d)) {
        return (*val = true);
    } else if (patterns[p][0]) { // 2 x 2
        const int diff =
            patterns[p][0] + patterns[p][1] - patterns[p][2] - patterns[p][3];
        return (*val = tile(p - 1, m - 2, d - diff) ||
                       tile(p - 1, m - 2, d + diff));
    } else { // 2 x 1
        const int diff = patterns[p][1] - patterns[p][2];
        return (*val = tile(p - 1, m - 1, d - diff) ||
                       tile(p - 1, m - 1, d + diff));
    }
}

char row[2][MAX_M + 1];
void reconstruct(int p, int m, int d)
{
    if (m <= 0) {
        return;
    }

    if (tile(p - 1, m, d)) {
        reconstruct(p - 1, m, d);
    } else if (patterns[p][0]) { // 2 x 2
        const int diff =
            patterns[p][0] + patterns[p][1] - patterns[p][2] - patterns[p][3];
        if (tile(p - 1, m - 2, d - diff)) {
            row[0][m] = patterns[p][0];
            row[0][m - 1] = patterns[p][1];
            row[1][m] = patterns[p][2];
            row[1][m - 1] = patterns[p][3];
            reconstruct(p - 1, m - 2, d - diff);
        } else if (tile(p - 1, m - 2, d + diff)) {
            row[1][m] = patterns[p][0];
            row[1][m - 1] = patterns[p][1];
            row[0][m] = patterns[p][2];
            row[0][m - 1] = patterns[p][3];
            reconstruct(p - 1, m - 2, d + diff);
        }
    } else { // 2 x 1
        const int diff = patterns[p][1] - patterns[p][2];
        if (tile(p - 1, m - 1, d - diff)) {
            row[0][m] = -patterns[p][1];
            row[1][m] = -patterns[p][2];
            reconstruct(p - 1, m - 1, d - diff);
        } else if (tile(p - 1, m - 1, d + diff)) {
            row[1][m] = -patterns[p][1];
            row[0][m] = -patterns[p][2];
            reconstruct(p - 1, m - 1, d + diff);
        }
    }
}

int main(void)
{
    int k, m;
    scanf("%d %d", &k, &m);

    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= i && i + j <= k + 1; ++j) {
            ++pat_cnt;
            if (i + j == k + 1) {
                patterns[pat_cnt][1] = i;
                patterns[pat_cnt][2] = j;
            } else {
                patterns[pat_cnt][0] = i;
                patterns[pat_cnt][1] = j;
                patterns[pat_cnt][2] = k - i + 1;
                patterns[pat_cnt][3] = k - j + 1;
            }
        }
    }

    memset(dp, -1, sizeof dp);
    if (tile(pat_cnt, m, 0)) {
        puts("YES");
        reconstruct(pat_cnt, m, 0);

        for (int i = 0; i <= 1; ++i) {
            for (int j = 1; j <= m; ++j) {
                printf("%d%c", row[i][j], j < m ? ' ' : '\n');
            }
        }
    } else {
        puts("NO");
    }
}
