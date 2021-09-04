#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>

constexpr int STR_LEN{1'000'001};
char pattern[STR_LEN];
char text[STR_LEN];
int pi[STR_LEN];

std::vector<int> match()
{
    const int len_pattern{static_cast<int>(strlen(pattern))};
    const int len_text{static_cast<int>(strlen(text))};

    pi[1] = 0;
    int k{0};
    for (int q{2}; q <= len_pattern; ++q) {
        while (k && pattern[k] != pattern[q - 1]) {
            k = pi[k];
        }
        if (pattern[k] == pattern[q - 1]) {
            ++k;
        }
        pi[q] = k;
    }

    std::vector<int> result;
    int q{0};
    for (int i{1}; i <= len_text; ++i) {
        while (q && pattern[q] != text[i - 1]) {
            q = pi[q];
        }
        if (pattern[q] == text[i - 1]) {
            ++q;
        }
        if (q == len_pattern) {
            result.push_back(i - q + 1);
            q = pi[q];
        }
    }
    return result;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin.getline(text, sizeof text);
    std::cin.getline(pattern, sizeof pattern);

    const auto result{match()};
    std::cout << result.size() << '\n';
    if (!result.empty()) {
        copy(begin(result), end(result) - 1,
             std::ostream_iterator<int>(std::cout, " "));
        std::cout << result.back();
    }
    std::cout << '\n';
}
