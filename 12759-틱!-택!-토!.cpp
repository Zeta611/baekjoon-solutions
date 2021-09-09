#include <iostream>

int board[3][3];

int done()
{
    for (int i{0}; i < 3; ++i) {
        if (const int player{board[i][i]}) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return player;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return player;
            }
        }
    }

    if (const int player{board[1][1]}) {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return player;
        }
        if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
            return player;
        }
    }

    return 0;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int player;
    std::cin >> player;

    int y, x;
    while (std::cin >> y) {
        std::cin >> x;

        board[y - 1][x - 1] = player;
        if (const int winner{done()}) {
            std::cout << winner << '\n';
            return 0;
        }

        player = player == 1 ? 2 : 1;
    }

    std::cout << "0\n";
}
