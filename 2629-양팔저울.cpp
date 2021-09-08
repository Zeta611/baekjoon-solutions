#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>

constexpr int MAX{40'000 + 500 * 30};
int weights[30];
int cases[7];
int dp[30][MAX + 1];

bool check(int n, int w)
{
    if (w == 0) {
        return true;
    }
    if (n == 0) {
        return false;
    }
    if (w < 0) {
        w = -w;
    }
    int &val{dp[n - 1][w]};
    if (val >= 0) {
        return val;
    }
    return val = check(n - 1, w) || check(n - 1, w - weights[n - 1]) ||
                 check(n - 1, w + weights[n - 1]);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    copy_n(std::istream_iterator<int>(std::cin), n, std::begin(weights));

    int t;
    std::cin >> t;
    copy_n(std::istream_iterator<int>(std::cin), t, std::begin(cases));

    memset(dp, -1, sizeof dp);
    for (int i{0}; i < t; ++i) {
        std::cout << (check(n, cases[i]) ? 'Y' : 'N')
                  << (i < t - 1 ? ' ' : '\n');
    }
}
