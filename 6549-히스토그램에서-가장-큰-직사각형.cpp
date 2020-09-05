#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>

long long max_rect(const std::vector<int>& hist)
{
    long long ret{0};
    std::stack<std::vector<int>::const_iterator> stack;
    auto it = begin(hist);
    while (it != end(hist) || !stack.empty()) {
        // Invar1: `stack` is monotonically increasing.
        // Invar2: `stack[i]` is shorter than all bars after `stack[i-1]`.
        if (it != end(hist) && (stack.empty() || *stack.top() <= *it)) {
            stack.push(it++);
        } else {
            // `it` is the exclusive right barrier (invar1)
            auto top_it = stack.top();
            stack.pop();
            // `left_barr` is the inclusive left barrier (invar2)
            auto left_barr = stack.empty() ? begin(hist) : next(stack.top());
            long long area = std::distance(left_barr, it) * *top_it;
            ret = std::max(ret, area);
        }
    }
    return ret;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<int> hist;
    hist.reserve(10'000);
    while (true) {
        int n;
        std::cin >> n;
        if (n == 0) {
            break;
        }
        std::copy_n(
            std::istream_iterator<int>(std::cin), n, back_inserter(hist));
        std::cout << max_rect(hist) << '\n';
        hist.clear();
    }
    return 0;
}
