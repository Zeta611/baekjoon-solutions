#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void choose(int n, int m, std::vector<bool>& check, std::vector<int>& comb)
{
    if (m == 0) {
        std::copy(
            begin(comb), end(comb),
            std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n';
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (check[i - 1]) {
            continue;
        }
        comb.push_back(i);
        check[i - 1] = true;
        choose(n, m - 1, check, comb);
        comb.pop_back();
        check[i - 1] = false;
    }
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> comb;
    comb.reserve(m);
    std::vector<bool> check(8, false);
    choose(n, m, check, comb);
    return 0;
}
