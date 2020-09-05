#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <stack>
#include <tuple>
#include <vector>

int get_state(
    const std::vector<int>& paper, int dim, int row, int column, int width)
{
    int hd{paper[row * dim + column]};
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < width; ++j) {
            if (hd != paper[(row + i) * dim + column + j]) {
                return 2;
            }
        }
    }
    return hd;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> paper;
    paper.reserve(n * n);
    std::copy_n(
        std::istream_iterator<int>(std::cin), n * n, back_inserter(paper));

    std::array<int, 3> cnt{};
    std::stack<std::tuple<int, int, int>> stack;
    stack.push({0, 0, n});
    while (!stack.empty()) {
        auto [row, column, width] = stack.top();
        stack.pop();
        int s{get_state(paper, n, row, column, width)};
        if (s < 2) {
            ++cnt[s + 1];
        } else {
            int hw = width / 3;
            stack.push({row + 2 * hw, column + 2 * hw, hw});
            stack.push({row + 2 * hw, column + hw, hw});
            stack.push({row + 2 * hw, column, hw});
            stack.push({row + hw, column + 2 * hw, hw});
            stack.push({row + hw, column + hw, hw});
            stack.push({row + hw, column, hw});
            stack.push({row, column + 2 * hw, hw});
            stack.push({row, column + hw, hw});
            stack.push({row, column, hw});
        }
    }

    for (int e : cnt) {
        std::cout << e << '\n';
    }

    return 0;
}
