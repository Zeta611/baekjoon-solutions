#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <utility>
#include <vector>

using point = std::pair<int, int>;

inline int square(int n)
{
    return n * n;
}

inline int dist_sq(point p1, point p2)
{
    return square(p2.first - p1.first) + square(p2.second - p1.second);
}

int brute_closest_path_sq(
    std::vector<point>::iterator first,
    std::vector<point>::iterator last)
{
    // Sort by y-coordinate.
    std::sort(
        first, last,
        [](point p1, point p2) { return p1.second < p2.second; });

    int dist{std::numeric_limits<int>::max()};
    for (auto i = first; i != last; ++i) {
        for (auto j = std::next(i); j != last; ++j) {
            dist = std::min(dist, dist_sq(*i, *j));
        }
    }
    return dist;
}

int closest_path_sq(
    std::vector<point>::iterator first,
    std::vector<point>::iterator last)
{
    if (std::distance(first, last) <= 3) {
        return brute_closest_path_sq(first, last);
    }

    auto middle{std::next(first, std::distance(first, last) / 2)};
    int mid_x{middle->first};

    int dist_l{closest_path_sq(first, middle)};
    int dist_r{closest_path_sq(middle, last)};
    int dist{std::min(dist_l, dist_r)};

    std::inplace_merge(
        first, middle, last,
        [](point p1, point p2) { return p1.second < p2.second; });

    std::vector<point> strip;
    std::copy_if(
        first, last, std::back_inserter(strip),
        [=](point p) { return square(p.first - mid_x) < dist; });

    for (auto i = begin(strip); i != end(strip); ++i) {
        for (auto j = next(i); j != end(strip) && j != next(i, 6); ++j) {
            dist = std::min(dist, dist_sq(*i, *j));
        }
    }
    return dist;
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<point> points(n);
    for (auto& p : points) {
        std::cin >> p.first >> p.second;
    }

    // Sort by x-coordinate.
    std::sort(
        begin(points), end(points),
        [](point p1, point p2) { return p1.first < p2.first; });

    std::cout << closest_path_sq(begin(points), end(points)) << '\n';
    return 0;
}
