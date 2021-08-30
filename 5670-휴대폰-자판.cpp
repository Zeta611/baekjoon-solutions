#include <cstring>
#include <iostream>

#define ATOI(c) ((c) - 'a')

constexpr int TRIE_SIZE{1'000'000};
constexpr int MAX_WORD_CNT{100'000};
constexpr int MAX_STR_LEN{81};
constexpr int ALPH_CNT{'z' - 'a' + 1};

struct Trie;
extern Trie tries[TRIE_SIZE];
int trie_alloc();
struct Trie {
    int children[ALPH_CNT];
    int child_cnt;
    bool terminal;

    inline void clear() { memset(this, 0, sizeof *this); }

    void put(const char *word)
    {
        if (!*word) {
            terminal = true;
            return;
        }

        const int c{ATOI(*word)};
        if (children[c]) {
            tries[children[c]].put(word + 1);
        } else {
            ++child_cnt;
            tries[children[c] = trie_alloc()].put(word + 1);
        }
    }

    int type_cnt(const char *word, int cnt = 1) const
    {
        if (!*word) {
            return cnt;
        }

        if (this != tries && (terminal || child_cnt > 1)) {
            ++cnt;
        }
        return tries[children[ATOI(*word)]].type_cnt(word + 1, cnt);
    }
} tries[TRIE_SIZE];
int trie_cnt;
inline int trie_alloc()
{
    tries[trie_cnt].clear();
    return trie_cnt++;
}

char dict[MAX_WORD_CNT][MAX_STR_LEN];
constexpr std::size_t s{sizeof tries + sizeof dict};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout.precision(2);
    std::cout << std::fixed;

    int n;
    while (std::cin >> n) {
        trie_cnt = 0;
        trie_alloc();

        for (int i{0}; i < n; ++i) {
            std::cin >> dict[i];
            tries[0].put(dict[i]);
        }

        int cnt{0};
        for (int i{0}; i < n; ++i) {
            cnt += tries[0].type_cnt(dict[i]);
        }
        std::cout << static_cast<double>(cnt) / n << '\n';
    }
}
