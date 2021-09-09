#include <algorithm>
#include <iostream>
#include <set>

constexpr int pow(int base, int exp)
{
    return exp == 0 ? 1 : base * pow(base, exp - 1);
}
constexpr int power3[10] = {
    pow(3, 0), pow(3, 1), pow(3, 2), pow(3, 3), pow(3, 4),
    pow(3, 5), pow(3, 6), pow(3, 7), pow(3, 8), pow(3, 9),
};

constexpr char O{1};
constexpr char X{2};
char board[3][3];

std::set<int> possible_states;

int hash()
{
    int val{0};
    int shift{0};
    for (int i{0}; i < 3; ++i) {
        for (int j{0}; j < 3; ++j) {
            val += board[i][j] * power3[shift++];
        }
    }
    return val;
}

bool done()
{
    // row/col
    for (int i{0}; i < 3; ++i) {
        if (board[i][i]) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return true;
            }
        }
    }

    // diag
    if (board[1][1]) {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        }
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true;
        }
    }

    // full
    for (int i{0}; i < 3; ++i) {
        for (int j{0}; j < 3; ++j) {
            if (!board[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void generate(char turn = X)
{
    if (done()) {
        possible_states.insert(hash());
        return;
    }

    for (int i{0}; i < 3; ++i) {
        for (int j{0}; j < 3; ++j) {
            if (board[i][j]) {
                continue;
            }

            board[i][j] = turn;
            generate(turn == O ? X : O);
            board[i][j] = 0;
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    generate();

    char buf[10];
    while (true) {
        std::cin >> buf;
        if (buf[0] == 'e') {
            break;
        }

        for (int i{0}; i < 9; ++i) {
            switch (buf[i]) {
            case '.':
                board[i / 3][i % 3] = 0;
                break;
            case 'O':
                board[i / 3][i % 3] = O;
                break;
            case 'X':
                board[i / 3][i % 3] = X;
                break;
            }
        }
        std::cout << (possible_states.contains(hash()) ? "valid\n"
                                                       : "invalid\n");
    }
}
