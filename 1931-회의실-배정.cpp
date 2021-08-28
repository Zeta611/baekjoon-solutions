#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int max_choose(std::vector<std::pair<int, int>> &schedule)
{
    std::sort(std::begin(schedule), std::end(schedule));

    int cnt{0};
    int last_end{0};
    for (const auto &[e, s] : schedule) {
        if (last_end <= s) {
            last_end = e;
            ++cnt;
        }
    }
    return cnt;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> schedule;
    schedule.reserve(n);
    while (n--) {
        int s, e;
        std::cin >> s >> e;
        schedule.emplace_back(e, s);
    }

    std::cout << max_choose(schedule) << '\n';
}
