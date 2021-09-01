#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <queue>
#include <utility>
#include <vector>

using Position = std::pair<int, int>;
constexpr int WIDTH{50};
constexpr Position dir[]{{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

bool map[WIDTH][WIDTH];
bool visited[WIDTH][WIDTH];
int bfs(int m, int n)
{
    std::memset(visited, false, sizeof visited);

    for (int i{0}; i < n; ++i) {
        for (int j{0}; j < m; ++j) {
            if (map[i][j] == false) {
                visited[i][j] = true;
            }
        }
    }

    int cnt{0};

    int i{0};
    int j{0};
    std::queue<Position> q;
    while (i < n && j < m) {
        if (visited[i][j]) {
            goto iterate;
        }

        ++cnt;
        visited[i][j] = true;
        q.emplace(i, j);
        while (!q.empty()) {
            const auto [y, x]{q.front()};
            q.pop();

            for (const auto [dx, dy] : dir) {
                const int nx{x + dx};
                const int ny{y + dy};
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[ny][nx]) {
                    continue;
                }

                visited[ny][nx] = true;
                q.emplace(ny, nx);
            }
        }

    iterate:
        if (++j == m) {
            j = 0;
            ++i;
        }
    }

    return cnt;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int m, n, k;
        std::cin >> m >> n >> k;

        std::memset(map, false, sizeof map);
        while (k--) {
            int x, y;
            std::cin >> x >> y;
            map[y][x] = true;
        }

        std::cout << bfs(m, n) << '\n';
    }
}
