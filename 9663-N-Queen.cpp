#include <iostream>
#include <vector>

int queen(int depth, int width, std::vector<int> &board)
{
    int count{0};
    if (depth == width) {
        return 1;
    }
    for (int i = 0; i < width; ++i) {
        bool possible{true};
        for (int j = 0; j < depth; ++j) {
            const int prev{board[j]};
            const int diag{depth - j};
            if (prev == i || prev - diag == i || prev + diag == i) {
                possible = false;
                break;
            }
        }
        if (!possible) {
            continue;
        }
        board.push_back(i);
        count += queen(depth + 1, width, board);
        board.pop_back();
    }
    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> board;
    board.reserve(n);
    std::cout << queen(0, n, board) << '\n';
    return 0;
}
