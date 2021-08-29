#include <algorithm>
#include <iostream>
#include <iterator>
#include <stack>
#include <vector>

long long largest_rect(const std::vector<int> &histogram)
{
    long long max{0};
    std::stack<int> left_bounds;

    for (int i{0}; i < histogram.size(); ++i) {
        while (!left_bounds.empty() &&
               histogram[left_bounds.top()] > histogram[i]) {
            const int h{histogram[left_bounds.top()]};
            left_bounds.pop();

            max = std::max(
                max,
                h * static_cast<long long>(
                        i - (left_bounds.empty() ? 0 : left_bounds.top() + 1)));
        }
        left_bounds.push(i);
    }

    while (!left_bounds.empty()) {
        const int h{histogram[left_bounds.top()]};
        left_bounds.pop();

        max = std::max(
            max, h * static_cast<long long>(
                         histogram.size() -
                         (left_bounds.empty() ? 0 : left_bounds.top() + 1)));
    }

    return max;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> histogram;
    while (true) {
        histogram.clear();

        int n;
        std::cin >> n;
        if (!n) {
            break;
        }

        copy_n(std::istream_iterator<int>(std::cin), n,
               back_inserter(histogram));

        std::cout << largest_rect(histogram) << '\n';
    }
}
