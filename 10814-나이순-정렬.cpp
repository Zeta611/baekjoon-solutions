#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <tuple>
#include <vector>

struct member : std::tuple<int, int, std::string>
{
    using std::tuple<int, int, std::string>::tuple;
};

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
    members.reserve(n);
    for (int i = 0; i < n; ++i) {
        int age;
        std::string name;
        std::cin >> age >> name;
        members.push_back({age, i, name});
    }

    std::sort(begin(members), end(members));

    std::copy(begin(members), end(members),
              std::ostream_iterator<member>(std::cout, "\n"));

    return 0;
}
