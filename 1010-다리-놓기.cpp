#include <cstring>
#include <iostream>

int memo[30][30];
int choose(int m, int n)
{
    if (m == 0 || n == 0 || m == n) {
        return 1;
    }

    int &ret{memo[m][n]};
    if (ret == -1) {
        return ret = choose(m - 1, n - 1) + choose(m - 1, n);
    }

    return ret;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::memset(memo, -1, sizeof memo);

    int t;
    std::cin >> t;
    for (int i{0}; i < t; ++i) {
        int n, m;
        std::cin >> n >> m;
        std::cout << choose(m, n) << '\n';
    }
}
