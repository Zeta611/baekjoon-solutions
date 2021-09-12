#include <stdio.h>
#include <string.h>

const char codes[][5] = {
    ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
    ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
    "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--..",
};

typedef struct Trie {
    int children[2];
    int terminal;
} Trie;

int tcnt;
Trie tnodes[10000 * 20 * 4 + 1];
int max_depth;

static inline int talloc()
{
    memset(&tnodes[tcnt], 0, sizeof(Trie));
    return tcnt++;
}

char word[21];
void put()
{
    int depth = 0;

    int t = 0;
    for (const char *wp = word; *wp; ++wp) {
        for (const char *c = codes[*wp - 'A']; *c; ++c) {
            ++depth;

            int nt;
            if (!(nt = tnodes[t].children[*c - '-'])) {
                t = tnodes[t].children[*c - '-'] = talloc();
            } else {
                t = nt;
            }
        }
    }
    ++tnodes[t].terminal;

    if (depth > max_depth) {
        max_depth = depth;
    }
}

int seq_len;
char seq[10001];
int dp[10001];
int ambiguity(int i)
{
    if (i >= seq_len) {
        return 1;
    }

    int *val = &dp[i];
    if (*val >= 0) {
        return *val;
    }

    int cnt = 0;
    int t = 0;
    for (int len = 1; i + len <= seq_len && len <= max_depth; ++len) {
        if (!(t = tnodes[t].children[seq[i + len - 1] - '-'])) {
            break;
        }

        const int match = tnodes[t].terminal;
        if (match) {
            cnt += match * ambiguity(i + len);
        }
    }
    return *val = cnt;
}

static inline void init()
{
    tcnt = max_depth = 0;
    talloc();
    memset(dp, -1, sizeof dp);
}

int main(void)
{
    int d;
    scanf("%d", &d);
    while (d--) {
        init();

        scanf("%s", seq);
        seq_len = strlen(seq);

        int n;
        scanf("%d", &n);
        while (n--) {
            scanf("%s", word);
            put();
        }

        printf("%d\n", ambiguity(0));
    }
}
