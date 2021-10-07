#include <iostream>
#include <queue>
#include <vector>

int numbers[1'000'000];
bool valid[1'000'000];
constexpr auto greater{[](int a, int b) { return numbers[a] > numbers[b]; }};
constexpr auto less{[](int a, int b) { return numbers[a] < numbers[b]; }};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--) {
        std::priority_queue<int, std::vector<int>, decltype(greater)> min_pq;
        std::priority_queue<int, std::vector<int>, decltype(less)> max_pq;

        int k;
        std::cin >> k;

        for (int i{0}; i < k; ++i) {
            char op;
            int n;
            std::cin >> op >> n;
            switch (op) {
            case 'I':
                numbers[i] = n;
                valid[i] = true;
                min_pq.push(i);
                max_pq.push(i);
                break;
            case 'D':
                if (n == 1) {
                    while (!max_pq.empty() && !valid[max_pq.top()]) {
                        max_pq.pop();
                    }
                    if (!max_pq.empty()) {
                        valid[max_pq.top()] = false;
                        max_pq.pop();
                    }
                } else {
                    while (!min_pq.empty() && !valid[min_pq.top()]) {
                        min_pq.pop();
                    }
                    if (!min_pq.empty()) {
                        valid[min_pq.top()] = false;
                        min_pq.pop();
                    }
                }
                break;
            }
        }

        while (!max_pq.empty() && !valid[max_pq.top()]) {
            max_pq.pop();
        }
        if (max_pq.empty()) {
            std::cout << "EMPTY\n";
            continue;
        } else {
            std::cout << numbers[max_pq.top()] << ' ';
        }
        while (!min_pq.empty() && !valid[min_pq.top()]) {
            min_pq.pop();
        }
        std::cout << numbers[min_pq.top()] << '\n';
    }
}
