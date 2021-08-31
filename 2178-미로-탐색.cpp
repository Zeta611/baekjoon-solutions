#include <iostream>
#include <queue>
#include <utility>

constexpr int WIDTH{100};
constexpr int dx[]{1, 0, -1, 0};
constexpr int dy[]{0, -1, 0, 1};
int bfs(int n, int m, char (*maze)[WIDTH + 1])
{
    int dist[WIDTH][WIDTH]{};

    std::queue<std::pair<int, int>> q{{{0, 0}}};
    dist[0][0] = 1;
    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();

        for (int i{0}; i < 4; ++i) {
            const int ny{y + dy[i]};
            const int nx{x + dx[i]};
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || maze[ny][nx] == '0') {
                continue;
            }
            if (!dist[ny][nx]) {
                q.emplace(ny, nx);
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
    }
    return dist[n - 1][m - 1];
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    char maze[WIDTH][WIDTH + 1];
    for (int i{0}; i < n; ++i) {
        std::cin >> maze[i];
    }

    std::cout << bfs(n, m, maze) << '\n';
}
