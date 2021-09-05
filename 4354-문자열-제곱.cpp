#include <cstring>
#include <iostream>

constexpr int STR_LEN{1'000'001};
char text[STR_LEN];
int pi[STR_LEN];

int longest_repeating_pattern()
{
    const int len{static_cast<int>(strlen(text))};
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

    const int period{len - pi[len]};
    if (len % period) {
        return 1;
    }
    return len / period;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true) {
        std::cin.getline(text, sizeof text);
        if (*text == '.') {
            break;
        }
        std::cout << longest_repeating_pattern() << '\n';
    }
}
