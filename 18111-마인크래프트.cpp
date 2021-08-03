#include <iostream>
#include <limits>
#include <utility>

long hcnt[257];

std::pair<long, int> flatten(int n, int m, long b)
{
    long min_time{std::numeric_limits<long>::max()};
    int height;
    for (int h{0}; h <= 256; ++h) {
        long remains{b};
        long time{0};
        for (int i{0}; i <= 256; ++i) {
            const long diff{(i - h) * hcnt[i]};
            if (diff > 0) {
                remains += diff;
                time += 2 * diff;
            } else if (diff < 0) {
                remains += diff;
                time -= diff;
            }
        }
        if (remains >= 0 &&
            (min_time > time || min_time == time && height < h)) {
            min_time = time;
            height = h;
        }
    }
    return {min_time, height};
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    long b;
    std::cin >> n >> m >> b;
    for (int i{0}; i < n * m; ++i) {
        int c;
        std::cin >> c;
        ++hcnt[c];
    }
    const auto [t, h]{flatten(n, m, b)};
    std::cout << t << ' ' << h << '\n';
}
