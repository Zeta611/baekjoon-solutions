#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int lis_len(const std::vector<int>& a)
{
    std::vector<int> tails;
    for (int e : a) {
        const auto it = std::lower_bound(begin(tails), end(tails), e);
        if (it == std::end(tails)) {
            tails.push_back(e);
        } else {
            *it = e;
        }
    }
    return tails.size();
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> a;
    a.reserve(n);
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(a));

    std::cout << lis_len(a) << '\n';

    return 0;
}
