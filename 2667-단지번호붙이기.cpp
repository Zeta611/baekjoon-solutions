#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <utility>
#include <vector>

using Position = std::pair<int, int>;
constexpr int WIDTH{25};
constexpr Position dir[]{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

char map[WIDTH][WIDTH + 1];
bool visited[WIDTH][WIDTH];
std::vector<int> bfs(int n)
{
    for (int i{0}; i < n; ++i) {
        for (int j{0}; j < n; ++j) {
            if (map[i][j] == '0') {
                visited[i][j] = true;
            }
        }
    }

    std::vector<int> sectors;

    int i{0};
    int j{0};
    std::queue<Position> q;
    while (i < n && j < n) {
        int cnt{1};
        if (visited[i][j]) {
            goto iterate;
        }

        visited[i][j] = true;
        q.emplace(i, j);
        while (!q.empty()) {
            const auto [y, x]{q.front()};
            q.pop();

            for (const auto [dx, dy] : dir) {
                const int nx{x + dx};
                const int ny{y + dy};
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[ny][nx]) {
                    continue;
                }

                visited[ny][nx] = true;
                q.emplace(ny, nx);
                ++cnt;
            }
        }

        sectors.push_back(cnt);

    iterate:
        if (++j == n) {
            j = 0;
            ++i;
        }
    }

    sort(begin(sectors), end(sectors));
    return sectors;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    for (int i{0}; i < n; ++i) {
        std::cin >> map[i];
    }

    const auto sectors{bfs(n)};
    std::cout << sectors.size() << '\n';
    std::copy(begin(sectors), end(sectors),
              std::ostream_iterator<int>(std::cout, "\n"));
}
