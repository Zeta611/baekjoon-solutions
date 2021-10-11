#include <iostream>

int f_pow2[20][200'001];
int f(int n, int x)
{
    for (int p{1}; n; ++p, n /= 2) {
        if (n % 2) {
            x = f_pow2[p][x];
        }
    }
    return x;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m;
    std::cin >> m;
    for (int x{1}; x <= m; ++x) {
        std::cin >> f_pow2[1][x];
    }
    for (int n{2}; n < 20; ++n) {
        for (int x{1}; x <= m; ++x) {
            f_pow2[n][x] = f_pow2[n - 1][f_pow2[n - 1][x]];
        }
    }

    int q;
    std::cin >> q;
    while (q--) {
        int n, x;
        std::cin >> n >> x;
        std::cout << f(n, x) << '\n';
    }
}
