#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> seq{std::istream_iterator<int>(std::cin),
                         std::istream_iterator<int>()};

    std::vector<int> nge_seq(seq.size());
    std::stack<int> pending;
    for (int i{0}; i < seq.size(); ++i) {
        while (!pending.empty() && seq[pending.top()] < seq[i]) {
            nge_seq[pending.top()] = seq[i];
            pending.pop();
        }
        pending.push(i);
    }
    while (!pending.empty()) {
        nge_seq[pending.top()] = -1;
        pending.pop();
    }

    std::copy_n(begin(nge_seq), n - 1,
                std::ostream_iterator<int>(std::cout, " "));
    std::cout << nge_seq.back() << '\n';
}
