#include <iostream>
#include <queue>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::queue<int> q;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string op;
        std::cin >> op;
        if (op == "push") {
            int input;
            std::cin >> input;
            q.push(input);
        } else if (op == "pop") {
            if (q.empty()) {
                std::cout << "-1\n";
            } else {
                std::cout << q.front() << '\n';
                q.pop();
            }
        } else if (op == "size") {
            std::cout << q.size() << '\n';
        } else if (op == "empty") {
            std::cout << (q.empty() ? 1 : 0) << '\n';
        } else if (op == "front") {
            std::cout << (q.empty() ? -1 : q.front()) << '\n';
        } else if (op == "back") {
            std::cout << (q.empty() ? -1 : q.back()) << '\n';
        } else {
            return 1;
        }
    }

    return 0;
}
