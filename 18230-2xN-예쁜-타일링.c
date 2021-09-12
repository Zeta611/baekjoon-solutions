#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)b - *(int *)a; }

int tiles[2][2000];

int main(void)
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    for (int i = 0; i < a; ++i) {
        scanf("%d", &tiles[0][i]);
    }
    for (int i = 0; i < b; ++i) {
        scanf("%d", &tiles[1][i]);
    }

    qsort(tiles[0], a, sizeof tiles[0][0], cmp);
    qsort(tiles[1], b, sizeof tiles[1][0], cmp);

    int i = 0;
    int j = 0;
    int val = 0;
    if (n & 1) {
        val = tiles[0][i++];
        --n;
    }
    while (n) {
        if (j < b && i + 1 < a) {
            if (tiles[0][i] + tiles[0][i + 1] > tiles[1][j]) {
                val += tiles[0][i] + tiles[0][i + 1];
                i += 2;
            } else {
                val += tiles[1][j++];
            }
        } else if (j < b) {
            val += tiles[1][j++];
        } else {
            val += tiles[0][i] + tiles[0][i + 1];
            i += 2;
        }

        n -= 2;
    }
    printf("%d\n", val);
}
