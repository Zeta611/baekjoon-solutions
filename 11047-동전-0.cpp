#include <iostream>
#include <iterator>
#include <vector>

int min_coins(const std::vector<int> &coins, int k)
{
    int cnt{0};
    for (auto it{std::crbegin(coins)}; it != std::crend(coins); ++it) {
        cnt += k / *it;
        k %= *it;
    }
    return cnt;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> coins{std::istream_iterator<int>(std::cin),
                           std::istream_iterator<int>()};
    std::cout << min_coins(coins, k) << '\n';
}
