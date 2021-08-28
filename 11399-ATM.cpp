#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int min_wait(std::vector<int> &time)
{
    std::sort(begin(time), end(time));
    std::partial_sum(begin(time), end(time), begin(time));
    return std::accumulate(begin(time), end(time), 0);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> time{std::istream_iterator<int>(std::cin),
                          std::istream_iterator<int>()};

    std::cout << min_wait(time) << '\n';
}
