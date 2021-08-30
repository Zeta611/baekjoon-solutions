#include <iostream>
#include <string>
#include <utility>
#include <vector>

using ChildList = std::vector<std::pair<std::string, int>>;
constexpr int TRIE_SIZE{15'000 + 1};

struct Trie {
    ChildList children;
} tries[TRIE_SIZE];
int trie_cnt{1};

void put(const std::vector<std::string> &words)
{
    int t{0};
    for (const auto &word : words) {
        ChildList::const_iterator it;
        if ((it = find_if(begin(tries[t].children), end(tries[t].children),
                          [&word](const auto &p) {
                              return p.first == word;
                          })) != end(tries[t].children)) {
            t = it->second;
        } else {
            tries[t].children.emplace_back(word, trie_cnt);
            t = trie_cnt++;
        }
    }
}

void visit(int trie, int depth, const std::string *word)
{
    if (word) {
        for (int i{0}; i < depth - 1; ++i) {
            std::cout << "--";
        }
        std::cout << *word << '\n';
    }

    if (!tries[trie].children.empty()) {
        sort(begin(tries[trie].children), end(tries[trie].children));
        for (const auto &[w, t] : tries[trie].children) {
            visit(t, depth + 1, &w);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int k;
    std::vector<std::string> words;
    std::string w;
    while (n--) {
        words.clear();
        std::cin >> k;
        while (k--) {
            std::cin >> w;
            words.push_back(w);
        }
        put(words);
    }

    visit(0, 0, nullptr);
}
