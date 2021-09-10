#include <stdio.h>
#include <string.h>

char codes[][5] = {['A'] = ".-",
                   "-...",
                   "-.-.",
                   "-..",
                   ".",
                   "..-.",
                   "--.",
                   "....",
                   "..",
                   ".---",
                   "-.-",
                   ".-..",
                   "--",
                   "-.",
                   "---",
                   ".--.",
                   "--.-",
                   ".-.",
                   "...",
                   "-",
                   "..-",
                   "...-",
                   ".--",
                   "-..-",
                   "-.--",
                   "--..",
                   ['_'] = "..--",
                   [','] = ".-.-",
                   ['.'] = "---.",
                   ['?'] = "----"};
char codelen[] = {['A'] = 2, 4, 4,         3,         1,         4,        3, 4,
                  2,         4, 3,         4,         2,         2,        3, 4,
                  4,         3, 3,         1,         3,         4,        3, 4,
                  4,         4, ['_'] = 4, [','] = 4, ['.'] = 4, ['?'] = 4};

char encoded[101];
char cnt[100];
char morse[401];
void decode()
{
        memset(cnt, 0, sizeof cnt);

        char *morsep = morse;
        int i;
        for (i = 0; encoded[i]; ++i) {
                for (char *c = codes[encoded[i]]; *c; ++c) {
                        *morsep++ = *c;
                        ++cnt[i];
                }
        }

        morsep = morse;
        --i;
        for (; i >= 0; --i) {
                for (int j = 1; j < sizeof codes / sizeof codes[0]; ++j) {
                        if (codelen[j] == cnt[i] &&
                            !strncmp(morsep, codes[j], cnt[i])) {
                                putchar(j);
                                morsep += cnt[i];
                                break;
                        }
                }
        }
        putchar('\n');
}

int main(void)
{
        int n;
        scanf("%d", &n);

        for (int i = 1; i <= n; ++i) {
                printf("%d: ", i);
                scanf("%s", encoded);
                decode();
        }
}
