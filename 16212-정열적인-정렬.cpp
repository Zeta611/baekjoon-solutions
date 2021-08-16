#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

constexpr int MAX{500'000};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> seq{std::istream_iterator<int>(std::cin),
                         std::istream_iterator<int>()};
    std::sort(begin(seq), end(seq));
    std::copy(begin(seq), end(seq) - 1,
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << *(end(seq) - 1) << '\n';
}
