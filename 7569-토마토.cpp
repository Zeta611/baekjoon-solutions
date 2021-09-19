#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

constexpr std::tuple<int, int, int> DIRS[]{
    {-1, 0, 0}, {0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {0, -1, 0}, {1, 0, 0},
};

int tomatoes[100][100][100];
int dist[100][100][100];

inline bool in_range(int x, int w) { return x >= 0 && x < w; }

inline bool eligible(int z, int y, int x, int h, int n, int m)
{
    return in_range(z, h) && in_range(y, n) && in_range(x, m) &&
           dist[z][y][x] == -1 && tomatoes[z][y][x] == 0;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    memset(dist, -1, sizeof dist);

    int m, n, h;
    std::cin >> m >> n >> h;

    std::queue<std::tuple<int, int, int>> queue;

    for (int i{0}; i < h; ++i) {
        for (int j{0}; j < n; ++j) {
            for (int k{0}; k < m; ++k) {
                std::cin >> tomatoes[i][j][k];
                if (tomatoes[i][j][k] == 1) {
                    queue.emplace(i, j, k);
                    dist[i][j][k] = 0;
                }
            }
        }
    }

    while (!queue.empty()) {
        const auto [z, y, x]{queue.front()};
        queue.pop();

        const int nd{dist[z][y][x] + 1};

        for (const auto [dz, dy, dx] : DIRS) {
            const int nz{z + dz};
            const int ny{y + dy};
            const int nx{x + dx};
            if (eligible(nz, ny, nx, h, n, m)) {
                queue.emplace(nz, ny, nx);
                dist[nz][ny][nx] = nd;
            }
        }
    }

    int max_d = 0;
    for (int i{0}; i < h; ++i) {
        for (int j{0}; j < n; ++j) {
            for (int k{0}; k < m; ++k) {
                if (dist[i][j][k] == -1 && tomatoes[i][j][k] == 0) {
                    std::cout << "-1\n";
                    return 0;
                }

                max_d = std::max(max_d, dist[i][j][k]);
            }
        }
    }

    std::cout << max_d << '\n';
}
