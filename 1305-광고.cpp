#include <iostream>

constexpr int STR_LEN{1'000'001};
char text[STR_LEN];
int pi[STR_LEN];

int shortest_wrapping_word(int len)
{
    int k{0};
    pi[1] = 0;
    for (int q{2}; q <= len; ++q) {
        while (k && text[k] != text[q - 1]) {
            k = pi[k];
        }
        if (text[k] == text[q - 1]) {
            ++k;
        }
        pi[q] = k;
    }

    return len - pi[len];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int len;
    std::cin >> len >> text;
    std::cout << shortest_wrapping_word(len) << '\n';
}
