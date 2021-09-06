#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

constexpr int PERIOD{360'000};
std::vector<bool> clock1_concat(PERIOD * 2);
std::vector<bool> clock2(PERIOD);
int pi[PERIOD + 1];

bool compare(int n)
{
    int k{0};
    for (int q{2}; q <= PERIOD; ++q) {
        while (k && clock2[q - 1] != clock2[k]) {
            k = pi[k];
        }
        if (clock2[q - 1] == clock2[k]) {
            ++k;
        }
        pi[q] = k;
    }

    int q{0};
    for (int i{1}; i <= 2 * PERIOD; ++i) {
        while (q && clock1_concat[i - 1] != clock2[q]) {
            q = pi[q];
        }
        if (clock1_concat[i - 1] == clock2[q]) {
            ++q;
        }
        if (q == PERIOD) {
            return true;
        }
    }
    return false;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    for (int i{0}; i < n; ++i) {
        int j;
        std::cin >> j;
        clock1_concat[j] = clock1_concat[j + PERIOD] = true;
    }
    for (int i{0}; i < n; ++i) {
        int j;
        std::cin >> j;
        clock2[j] = true;
    }

    std::cout << (compare(n) ? "possible\n" : "impossible\n");
}
