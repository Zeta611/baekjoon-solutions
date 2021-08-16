#include <iostream>

long dp[21][21][21];

long w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }
    if (dp[a][b][c]) {
        return dp[a][b][c];
    }
    long val;
    if (a < b && b < c) {
        val = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    } else {
        val = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) -
              w(a - 1, b - 1, c - 1);
    }
    dp[a][b][c] = val;
    return val;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true) {
        int a, b, c;
        std::cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        std::cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c)
                  << '\n';
    }
}
