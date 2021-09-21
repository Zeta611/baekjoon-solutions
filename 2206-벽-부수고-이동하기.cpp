#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

constexpr std::tuple<int, int> DIRS[] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

char map[2][1000][1001];
int dist[2][1000][1001];

int min_dist(int n, int m)
{
    std::queue<std::tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    dist[0][0][0] = 1;

    while (!q.empty()) {
        const auto [z, y, x]{q.front()};
        const int d{dist[z][y][x]};
        if (y == n - 1 && x == m - 1) {
            return d;
        }
        q.pop();

        for (const auto &[dy, dx] : DIRS) {
            const int ny{y + dy};
            const int nx{x + dx};
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }

            if (z == 0 && map[0][ny][nx] == '1') {
                q.emplace(1, ny, nx);
                dist[1][ny][nx] = d + 1;
            } else if (map[z][ny][nx] == '0' && dist[z][ny][nx] == 0) {
                q.emplace(z, ny, nx);
                dist[z][ny][nx] = d + 1;
                if (z == 0) {
                    dist[1][ny][nx] = d + 1;
                }
            }
        }
    }

    return -1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    for (int i{0}; i < n; ++i) {
        std::cin >> map[0][i];
    }
    memcpy(map[1], map[0], sizeof map[0]);

    std::cout << min_dist(n, m) << '\n';
}
