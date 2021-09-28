#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::unordered_set<std::string> s1(n), s2(m);
    while (n--) {
        std::string s;
        std::cin >> s;
        s1.insert(s);
    }
    while (m--) {
        std::string s;
        std::cin >> s;
        s2.insert(s);
    }

    std::vector<std::string> intersection;
    for (const auto &s : s1) {
        if (s2.contains(s)) {
            intersection.push_back(s);
        }
    }
    sort(begin(intersection), end(intersection));
    std::cout << intersection.size() << '\n';
    for (const auto &s : intersection) {
        std::cout << s << '\n';
    }
}
