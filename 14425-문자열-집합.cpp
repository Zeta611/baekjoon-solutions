#include <iostream>

#define ATOI(c) ((c) - 'a')

constexpr int ALPH_CNT{'z' - 'a' + 1};
constexpr int MAX_STR_LEN{500};
constexpr int MAX_SET_SIZE{10'000};

struct Trie {
    int children[ALPH_CNT];
    bool terminal;
} tries[(MAX_STR_LEN + 1) * MAX_SET_SIZE + 1];
int trie_cnt{1};

void put(const char *str)
{
    int t{0};
    while (*str) {
        int i;
        const int c{ATOI(*str++)};
        if (!(i = tries[t].children[c])) {
            i = tries[t].children[c] = trie_cnt++;
        }
        t = i;
    }
    tries[t].terminal = true;
}

bool find(const char *str)
{
    int t{0};
    while (*str) {
        if (!(t = tries[t].children[ATOI(*str++)])) {
            return false;
        }
    }
    return tries[t].terminal;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    char buf[MAX_STR_LEN + 1];
    while (n--) {
        std::cin >> buf;
        put(buf);
    }

    int cnt{0};
    while (m--) {
        std::cin >> buf;
        if (find(buf)) {
            ++cnt;
        }
    }

    std::cout << cnt << '\n';
}
