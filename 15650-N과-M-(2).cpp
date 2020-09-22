#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void choose(int lo, int hi, int m, std::vector<int>& comb)
{
    if (m == 0) {
        std::copy(
            begin(comb), end(comb),
            std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';
        return;
    } else if (lo > hi) {
        return;
    }

    for (int i = lo; i <= hi; ++i) {
        comb.push_back(i);
        choose(i + 1, hi, m - 1, comb);
        comb.pop_back();
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> comb;
    comb.reserve(m);
    choose(1, n, m, comb);
    return 0;
}
