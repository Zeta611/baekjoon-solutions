#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> seq;
    seq.reserve(n);

    while (n--) {
        int m;
        std::cin >> m;
        seq.push_back(m);
    }

    int x;
    std::cin >> x;

    sort(begin(seq), end(seq));

    int cnt{0};
    int i{0};
    int j{static_cast<int>(size(seq) - 1)};
    while (i < j) {
        const int sum{seq[i] + seq[j]};
        if (sum > x) {
            --j;
        } else if (sum < x) {
            ++i;
        } else {
            ++cnt;
            ++i;
        }
    }

    std::cout << cnt << '\n';
}
