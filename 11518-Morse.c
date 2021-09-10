#include <stdbool.h>
#include <stdio.h>

char codes['Z' - 'A' + 1][5];

int word_cnt;
char words[101][101];

typedef struct Trie Trie;
struct Trie {
        int children[2];
        int word;
} nodes[4 * 100 * 100 + 1];
unsigned long long a = sizeof nodes;
int node_cnt;

char buf[4 * 100 + 1];
void insert(int word)
{
        char *bufp = buf;
        for (const char *letter = words[word]; *letter; ++letter) {
                for (const char *c = codes[*letter - 'A']; *c; ++c) {
                        *bufp++ = *c;
                }
        }
        *bufp = '\0';

        int trie = 0;
        for (bufp = buf; *bufp; ++bufp) {
                int t;
                if (!(t = nodes[trie].children[*bufp - '-'])) {
                        nodes[trie].children[*bufp - '-'] = t = ++node_cnt;
                }
                trie = t;
        }
        nodes[trie].word = word;
}

int get(const char *codes)
{
        int trie = 0;
        for (; *codes; ++codes) {
                if (!(trie = nodes[trie].children[*codes - '-'])) {
                        return 0;
                }
        }
        return nodes[trie].word;
}

int main(void)
{
        for (char c = 'A'; c <= 'Z'; ++c) {
                scanf("%*c %s\n", codes[c - 'A']);
        }

        scanf("%d", &word_cnt);
        for (int i = 1; i <= word_cnt; ++i) {
                scanf("%s", words[i]);
                insert(i);
        }

        int i;
        int sentence[101] = {0};
        int n;
        while (true) {
                scanf("%d", &n);
                if (!n) {
                        break;
                }

                i = 0;
                while (n--) {
                        scanf("%s", buf);
                        if (!(sentence[i++] = get(buf))) {
                                i = 0;
                                while (n--) {
                                        scanf("%*s");
                                }
                                break;
                        }
                }
                if (i) {
                        for (int j = 0; j < i; ++j) {
                                fputs(words[sentence[j]], stdout);
                                putchar(j < i - 1 ? ' ' : '\n');
                        }
                } else {
                        fputs(buf, stdout);
                        puts(" not in dictionary.");
                }
        }
}
