#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int max_dist(int lo, int hi, std::vector<int> houses, int c)
{
    if (hi - lo == 1) {
        return lo;
    }

    // Max distance to check.
    int mid = (lo + hi) / 2;

    // The latest position where a router is put.
    // Place the first router at the first house.
    int curr_pos = houses[0];
    int left_c = c - 1;

    for (auto it = ++begin(houses); left_c && it != end(houses); ++it) {
        int xi = *it;
        if (xi - curr_pos >= mid) {
            curr_pos = xi;
            --left_c;
        }
    }

    if (left_c) {
        // It is impossible to place routers with distance >= mid.
        return max_dist(lo, mid, houses, c);
    } else {
        return max_dist(mid, hi, houses, c);
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, c;
    std::cin >> n >> c;
    std::vector<int> houses;
    houses.reserve(n);
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(houses));

    std::sort(begin(houses), end(houses));
    std::cout << max_dist(1, 1'000'000'000, houses, c) << '\n';

    return 0;
}
