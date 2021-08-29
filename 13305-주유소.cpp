#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

long long min_cost(std::vector<long long> &dist,
                   const std::vector<long long> &price)
{
    long long cost{0};
    long long min{std::numeric_limits<long long>::max()};
    for (int i{0}; i < price.size(); ++i) {
        min = std::min(min, price[i]);
        cost += min * dist[i];
    }
    return cost;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<long long> dist;
    std::vector<long long> price;
    dist.reserve(n - 1);
    price.reserve(n - 1);
    std::copy_n(std::istream_iterator<long long>(std::cin), n - 1,
                back_inserter(dist));
    std::copy_n(std::istream_iterator<long long>(std::cin), n - 1,
                back_inserter(price));

    std::cout << min_cost(dist, price) << '\n';
}
