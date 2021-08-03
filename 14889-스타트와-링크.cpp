#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

inline int absmin(int a, int b) { return std::abs(a) < std::abs(b) ? a : b; }

int check(const std::vector<std::vector<int>> &points, int depth = 0,
          int diff = 0)
{
    static std::vector<int> team1;
    static std::vector<int> team2;

    if (depth == points.size()) {
        return diff;
    }
    int min_diff{std::numeric_limits<int>::max()};
    if (team1.size() < points.size() / 2) {
        team1.push_back(depth);
        int new_diff{diff};
        for (int i : team1) {
            new_diff += points[i][depth] + points[depth][i];
        }
        min_diff = absmin(min_diff, check(points, depth + 1, new_diff));
        team1.pop_back();
    }
    if (team2.size() < points.size() / 2) {
        team2.push_back(depth);
        int new_diff{diff};
        for (int i : team2) {
            new_diff -= points[i][depth] + points[depth][i];
        }
        min_diff = absmin(min_diff, check(points, depth + 1, new_diff));
        team2.pop_back();
    }
    return min_diff;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<int>> points(n);
    for (int i{0}; i < n; ++i) {
        for (int j{0}; j < n; ++j) {
            int m;
            std::cin >> m;
            points[i].push_back(m);
        }
    }
    std::cout << std::abs(check(points)) << '\n';
}
