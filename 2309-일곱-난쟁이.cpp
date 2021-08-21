#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> heights{std::istream_iterator<int>(std::cin),
                             std::istream_iterator<int>()};

    std::sort(begin(heights), end(heights));

    const int sum{accumulate(begin(heights), end(heights), 0)};

    for (auto i{std::cbegin(heights)}; i != std::cend(heights); ++i) {
        for (auto j{std::next(i)}; j != std::cend(heights); ++j) {
            if (sum - *i - *j == 100) {
                std::copy_if(begin(heights), end(heights),
                             std::ostream_iterator<int>(std::cout, "\n"),
                             [i, j](int h) { return h != *i && h != *j; });
                return 0;
            }
        }
    }

    return 0;
}
