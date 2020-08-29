#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    std::vector<int> a;
    a.reserve(n);
    std::copy_n(std::istream_iterator<int>(std::cin), n, back_inserter(a));
    std::sort(begin(a), end(a));

    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int b;
        std::cin >> b;
        std::cout << (std::binary_search(begin(a), end(a), b) ? 1 : 0)
                  << '\n';
    }

    return 0;
}
