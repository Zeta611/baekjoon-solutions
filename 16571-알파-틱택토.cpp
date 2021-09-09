#include <algorithm>
#include <iostream>

constexpr int X{1};
constexpr int O{2};

int board[3][3];

int hash()
{
    int val{0};
    for (int i{0}; i < 3; ++i) {
        for (int j{0}; j < 3; ++j) {
            val *= 3;
            val += board[i][j];
        }
    }
    return val;
}

constexpr int pow(int base, int exp)
{
    return exp == 0 ? 1 : base * pow(base, exp - 1);
}

constexpr char UNDETERMINED{2};
char dp[pow(3, 10)];

int turn()
{
    int xcnt{0};
    int ocnt{0};
    for (int i{0}; i < 3; ++i) {
        for (int j{0}; j < 3; ++j) {
            switch (board[i][j]) {
            case X:
                ++xcnt;
                break;
            case O:
                ++ocnt;
                break;
            }
        }
    }

    return xcnt == ocnt ? X : O;
}

bool winner(int turn)
{
    for (int i{0}; i < 3; ++i) {
        if (board[i][i] == turn) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return true;
            }
        }
    }

    if (board[1][1] == turn) {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        }
        if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
            return true;
        }
    }

    return false;
}

// 1 if `turn` can win, -1 if not, 0 if tie.
int solve(int turn)
{
    char &val{dp[hash()]};
    if (val != UNDETERMINED) {
        return val;
    }

    if (winner(O + X - turn)) {
        return val = -1;
    }

    int min{2};
    for (int i{0}; i < 3; ++i) {
        for (int j{0}; j < 3; ++j) {
            if (board[i][j]) {
                continue;
            }

            board[i][j] = turn;
            min = std::min(min, solve(O + X - turn));
            board[i][j] = 0;
        }
    }

    if (min == 2 || !min) {
        return val = 0;
    }
    return val = -min;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::fill(std::begin(dp), std::end(dp), UNDETERMINED);

    for (int i{0}; i < 3; ++i) {
        for (int j{0}; j < 3; ++j) {
            std::cin >> board[i][j];
        }
    }

    switch (solve(turn())) {
    case 1:
        std::cout << "W\n";
        break;
    case 0:
        std::cout << "D\n";
        break;
    case -1:
        std::cout << "L\n";
        break;
    }
}
