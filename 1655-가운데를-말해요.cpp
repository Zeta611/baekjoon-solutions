#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int median;
    // max heap
    std::priority_queue<int> lowerq;
    // min heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> upperq;

    --n;
    std::cin >> median;
    std::cout << median << '\n';
    while (n--) {
        int x;
        std::cin >> x;

        if (x < median) {
            lowerq.push(x);
            if (lowerq.size() == upperq.size() + 1) {
                upperq.push(median);
                median = lowerq.top();
                lowerq.pop();
            }
        } else if (x > median) {
            upperq.push(x);
            if (upperq.size() == lowerq.size() + 2) {
                lowerq.push(median);
                median = upperq.top();
                upperq.pop();
            }
        } else {
            if (upperq.size() == lowerq.size()) {
                upperq.push(x);
            } else { // upperq.size() == lowerq.size() + 1
                lowerq.push(x);
            }
        }

        std::cout << median << '\n';
    }
}
