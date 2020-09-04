#include <iostream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

enum class state
{
    white, black, mixed
};

state get_state(
    const std::vector<bool>& image, int dim, int row, int column, int width)
{
    bool hd{image[row * dim + column]};
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < width; ++j) {
            if (hd != image[(row + i) * dim + column + j]) {
                return state::mixed;
            }
        }
    }
    return hd ? state::black : state::white;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<bool> image;
    image.reserve(n * n);
    for (std::string row; std::getline(std::cin, row);) {
        for (char c : row) {
            image.push_back(c == '1');
        }
    }

    std::stack<std::tuple<int, int, int>> stack;
    stack.push({0, 0, n});
    while (!stack.empty()) {
        auto [row, column, width] = stack.top();
        stack.pop();
        if (row == -1) {
            std::cout << ')';
            continue;
        }
        state s{get_state(image, n, row, column, width)};
        switch (s) {
        case state::white:
            std::cout << 0;
            break;
        case state::black:
            std::cout << 1;
            break;
        case state::mixed:
            {
                int hw = width / 2;
                stack.push({-1, 0, 0});
                stack.push({row + hw, column + hw, hw});
                stack.push({row + hw, column, hw});
                stack.push({row, column + hw, hw});
                stack.push({row, column, hw});
                std::cout << '(';
                break;
            }
        }
    }
    std::cout << '\n';
    return 0;
}
