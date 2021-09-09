#include <iostream>

constexpr char O{1};
constexpr char X{2};
char board[3][3];

bool win(char turn)
{
    for (int i{0}; i < 3; ++i) {
        if (board[i][i] == turn) {
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return true;
            }
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true;
            }
        }
    }

    if (board[1][1] == turn) {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true;
        }
    }

    return false;
}

void solve(char turn)
{
    for (int i{0}; i < 3; ++i) {
        for (int j{0}; j < 3; ++j) {
            if (board[i][j]) {
                continue;
            }

            board[i][j] = turn;
            if (win(turn)) {
                return;
            }
            board[i][j] = 0;
        }
    }
}

void print_board()
{
    for (int i{0}; i < 3; ++i) {
        for (int j{0}; j < 3; ++j) {
            switch (board[i][j]) {
            case 0:
                std::cout << '-';
                break;
            case O:
                std::cout << 'o';
                break;
            case X:
                std::cout << 'x';
                break;
            }
        }
        std::cout << '\n';
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    for (int t{1}; t <= n; ++t) {
        for (int i{0}; i < 3; ++i) {
            for (int j{0}; j < 3; ++j) {
                char c;
                std::cin >> c;
                switch (c) {
                case '-':
                    board[i][j] = 0;
                    break;
                case 'o':
                    board[i][j] = O;
                    break;
                case 'x':
                    board[i][j] = X;
                    break;
                }
            }
        }

        char turn;
        std::cin >> turn;
        solve(turn == 'o' ? O : X);

        std::cout << "Case " << t << ":\n";
        print_board();
    }
}
