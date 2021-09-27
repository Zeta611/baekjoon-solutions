#include <stdio.h>
#include <string.h>

unsigned dist[101][101];

void floyd_warshall(int n)
{
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                const unsigned tmp = dist[i][k] + dist[k][j];
                if (tmp >= dist[i][k] // check overflow
                    && tmp < dist[i][j]) {
                    dist[i][j] = tmp;
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == -1) {
                dist[i][j] = 0;
            }
        }
    }
}

int main(void)
{
    memset(dist, -1, sizeof dist);

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }

    while (m--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (c < dist[a][b]) {
            dist[a][b] = c;
        }
    }

    floyd_warshall(n);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d%c", dist[i][j], j == n ? '\n' : ' ');
        }
    }
}
