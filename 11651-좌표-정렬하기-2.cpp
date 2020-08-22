#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

typedef std::pair<int, int> point;

std::ostream& operator<<(std::ostream& os, const point& pt)
{
    os << pt.first << ' ' << pt.second;
    return os;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<point> points;
    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        points.push_back(point(x, y));
    }

    std::sort(
        points.begin(),
        points.end(),
        [](point a, point b) -> bool {
            if (a.second != b.second) {
                return a.second < b.second;
            } else {
                return a.first < b.first;
            }
        }
    );

    for (const auto& point : points) {
        std::cout << point << '\n';
    }

    return 0;
}
