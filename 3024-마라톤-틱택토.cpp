#include <iostream>

char board[30][30];

char winner(int n)
{
    if (n < 3) {
        return 0;
    }

    for (int i{0}; i < n; ++i) {
        for (int j{0}; j < n; ++j) {
            if (board[i][j] == '.') {
                continue;
            }

            // row
            if (j + 2 < n) {
                if (board[i][j] == board[i][j + 1] &&
                    board[i][j + 1] == board[i][j + 2]) {
                    return board[i][j];
                }
            }
            // col
            if (i + 2 < n) {
                if (board[i][j] == board[i + 1][j] &&
                    board[i + 1][j] == board[i + 2][j]) {
                    return board[i][j];
                }
            }
            // diag
            if (i - 2 >= 0 && j + 2 < n) {
                if (board[i][j] == board[i - 1][j + 1] &&
                    board[i - 1][j + 1] == board[i - 2][j + 2]) {
                    return board[i][j];
                }
            }
            if (i + 2 < n && j + 2 < n) {
                if (board[i][j] == board[i + 1][j + 1] &&
                    board[i + 1][j + 1] == board[i + 2][j + 2]) {
                    return board[i][j];
                }
            }
        }
    }

    return 0;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    for (int i{0}; i < n; ++i) {
        for (int j{0}; j < n; ++j) {
            std::cin >> board[i][j];
        }
    }

    if (const char c{winner(n)}) {
        std::cout << c << '\n';
    } else {
        std::cout << "ongoing\n";
    }
}
