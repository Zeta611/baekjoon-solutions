#include <algorithm>
#include <iostream>
#include <limits>

int dim[501];
int dp[501][501];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    for (int i{0}; i < n; ++i) {
        std::cin >> dim[i];
        std::cin >> dim[i + 1];
    }

    for (int d{1}; d < n; ++d) {
        for (int i{0}; i < n - d; ++i) {
            const int j{i + d};

            int min{std::numeric_limits<int>::max()};
            for (int k{i}; k < j; ++k) {
                min = std::min(min, dp[i][k] + dp[k + 1][j] +
                                        dim[i] * dim[k + 1] * dim[j + 1]);
            }
            dp[i][j] = min;
        }
    }
    std::cout << dp[0][n - 1] << '\n';
}
