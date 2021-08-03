#include <algorithm>
#include <iostream>
#include <limits>
#include <tuple>
#include <utility>
#include <vector>

constexpr int int_max{std::numeric_limits<int>::max()};
constexpr int int_min{std::numeric_limits<int>::min()};

using MM = std::pair<int, int>;

MM max_min(const std::vector<int> &numbers, int plus, int minus, int times,
           int div, int depth = 0, int accum = 0)
{
    if (depth == 0) {
        return max_min(numbers, plus, minus, times, div, depth + 1, numbers[0]);
    }
    if (depth == numbers.size()) {
        return {accum, accum};
    }

    int max{int_min};
    int min{int_max};
    if (plus) {
        const auto [a, b]{max_min(numbers, plus - 1, minus, times, div,
                                  depth + 1, accum + numbers[depth])};
        max = std::max(a, max);
        min = std::min(b, min);
    }
    if (minus) {
        const auto [a, b]{max_min(numbers, plus, minus - 1, times, div,
                                  depth + 1, accum - numbers[depth])};
        max = std::max(a, max);
        min = std::min(b, min);
    }
    if (times) {
        const auto [a, b]{max_min(numbers, plus, minus, times - 1, div,
                                  depth + 1, accum * numbers[depth])};
        max = std::max(a, max);
        min = std::min(b, min);
    }
    if (div) {
        const auto [a, b]{max_min(numbers, plus, minus, times, div - 1,
                                  depth + 1, accum / numbers[depth])};
        max = std::max(a, max);
        min = std::min(b, min);
    }
    return {max, min};
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::vector<int> numbers;
    numbers.reserve(11);
    std::cin >> n;
    for (int i{0}; i < n; ++i) {
        int k;
        std::cin >> k;
        numbers.push_back(k);
    }
    int plus, minus, times, div;
    std::cin >> plus >> minus >> times >> div;

    const auto [max, min]{max_min(numbers, plus, minus, times, div)};
    std::cout << max << '\n' << min << '\n';
}
