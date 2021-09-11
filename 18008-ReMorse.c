#include <stdio.h>
#include <stdlib.h>

#define ALPH_CNT ('z' - 'a' + 1)

int str_len;
char str[32001];
int ch_cnt[ALPH_CNT];
char alph[ALPH_CNT];

int cmp(const void *c1, const void *c2)
{
    return ch_cnt[*(char *)c2] - ch_cnt[*(char *)c1];
}

int main()
{
    int c;
    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            str[str_len++] = c - 'a';
            ++ch_cnt[c - 'a'];
        } else if (c >= 'A' && c <= 'Z') {
            str[str_len++] = c - 'A';
            ++ch_cnt[c - 'A'];
        }
    }

    for (int i = 0; i < ALPH_CNT; ++i) {
        alph[i] = i;
    }
    qsort(alph, sizeof alph / sizeof *alph, sizeof *alph, cmp);

    for (int i = 0, f0 = 1, f1 = 1, rep = 0, j = -1; i < ALPH_CNT; ++i, --rep) {
        if (!rep) {
            rep = f1;
            j += 2;

            const int tmp = f1;
            f1 = f0 + f1;
            f0 = tmp;
        }
        ch_cnt[alph[i]] = j;
    }

    int cnt = 0;
    for (int i = 0; i < str_len; ++i) {
        cnt += ch_cnt[str[i]];
    }
    printf("%d\n", cnt + 3 * (str_len - 1));
}
