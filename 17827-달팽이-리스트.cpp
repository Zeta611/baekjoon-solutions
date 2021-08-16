#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

inline int index(int n, int v, int k)
{
    return k < v ? k + 1 : v + (k - v + 1) % (n - v + 1);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, v;
    std::cin >> n >> m >> v;

    std::vector<int> seq;
    std::copy_n(std::istream_iterator<int>(std::cin), n,
                std::back_inserter(seq));

    for (int i{0}; i < m; ++i) {
        int k;
        std::cin >> k;
        std::cout << seq[index(n, v, k) - 1] << '\n';
    }
}
