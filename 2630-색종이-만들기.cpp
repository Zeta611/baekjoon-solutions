#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <tuple>
#include <vector>

enum class state
{
    white, blue, mixed
};

state get_state(
    const std::vector<bool>& paper, int dim, int row, int column, int width)
{
    bool hd{paper[row * dim + column]};
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < width; ++j) {
            if (hd != paper[(row + i) * dim + column + j]) {
                return state::mixed;
            }
        }
    }
    return hd ? state::blue : state::white;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<bool> paper;
    paper.reserve(n * n);
    std::copy_n(
        std::istream_iterator<bool>(std::cin), n * n, back_inserter(paper));

    int white_cnt = 0;
    int blue_cnt = 0;
    std::stack<std::tuple<int, int, int>> stack;
    stack.push({0, 0, n});
    while (!stack.empty()) {
        auto [row, column, width] = stack.top();
        stack.pop();
        state s{get_state(paper, n, row, column, width)};
        switch (s) {
        case state::white:
            ++white_cnt;
            break;
        case state::blue:
            ++blue_cnt;
            break;
        case state::mixed:
            {
                int hw = width / 2;
                stack.push({row + hw, column + hw, hw});
                stack.push({row + hw, column, hw});
                stack.push({row, column + hw, hw});
                stack.push({row, column, hw});
                break;
            }
        }
    }
    std::cout << white_cnt << '\n' << blue_cnt << '\n';
    return 0;
}
