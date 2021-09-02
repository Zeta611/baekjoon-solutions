#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

constexpr int WIDTH{1'000};
constexpr std::pair<int, int> DIRS[]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int box[WIDTH][WIDTH];
int dist[WIDTH][WIDTH];
std::queue<std::pair<int, int>> q;

int bfs(int m, int n)
{
    while (!q.empty()) {
        const auto [y, x]{q.front()};
        q.pop();

        for (const auto [dy, dx] : DIRS) {
            const int ny{y + dy};
            const int nx{x + dx};
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || box[ny][nx] ||
                dist[ny][nx] > 0) {
                continue;
            }

            if (dist[ny][nx] == -1) {
                dist[ny][nx] = dist[y][x] + 1;
            } else {
                dist[ny][nx] = std::min(dist[ny][nx], dist[y][x] + 1);
            }
            q.emplace(ny, nx);
        }
    }

    int max{0};
    for (int i{0}; i < n; ++i) {
        for (int j{0}; j < m; ++j) {
            if (box[i][j] == 0 && dist[i][j] == -1) {
                return -1;
            }
            max = std::max(max, dist[i][j]);
        }
    }
    return max;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    memset(dist, -1, sizeof dist);

    int m, n;
    std::cin >> m >> n;

    for (int i{0}; i < n; ++i) {
        for (int j{0}; j < m; ++j) {
            std::cin >> box[i][j];
            if (box[i][j] == 1) {
                q.emplace(i, j);
                dist[i][j] = 0;
            }
        }
    }

    std::cout << bfs(m, n) << '\n';
}
