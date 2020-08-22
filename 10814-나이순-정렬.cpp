#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

typedef std::tuple<int, int, std::string> member;

std::ostream& operator<<(std::ostream& os, const member& mb)
{
    os << std::get<0>(mb) << ' ' << std::get<2>(mb);
    return os;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<member> members;
    for (int i = 0; i < n; ++i) {
        int age;
        std::string name;
        std::cin >> age >> name;
        members.push_back({age, i, name});
    }

    std::sort(members.begin(), members.end());

    for (const auto& member : members) {
        std::cout << member << '\n';
    }

    return 0;
}
