#include <cstring>
#include <iostream>
#include <queue>
#include <utility>

constexpr int WIDTH{300};
constexpr std::pair<int, int> DIRS[]{{-1, 2}, {-2, 1}, {-2, -1}, {-1, -2},
                                     {1, -2}, {2, -1}, {2, 1},   {1, 2}};

int dist[WIDTH][WIDTH];

int min_move(int curr_x, int curr_y, int dest_x, int dest_y, int width)
{
    if (curr_x == dest_x && curr_y == dest_y) {
        return 0;
    }

    memset(dist, -1, sizeof dist);

    std::queue<std::pair<int, int>> queue;
    queue.emplace(curr_y, curr_x);
    dist[curr_y][curr_x] = 0;

    while (!queue.empty()) {
        const auto [y, x]{queue.front()};
        queue.pop();

        const int nd{dist[y][x] + 1};

        for (const auto [dy, dx] : DIRS) {
            const int ny{y + dy};
            const int nx{x + dx};
            if (ny == dest_y && nx == dest_x) {
                return nd;
            } else if (ny >= 0 && ny < width && nx >= 0 && nx < width &&
                       dist[ny][nx] == -1) {
                queue.emplace(ny, nx);
                dist[ny][nx] = nd;
            }
        }
    }

    return -1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    while (n--) {
        int w;
        std::cin >> w;

        int curr_x, curr_y, dest_x, dest_y;
        std::cin >> curr_x >> curr_y >> dest_x >> dest_y;

        std::cout << min_move(curr_x, curr_y, dest_x, dest_y, w) << '\n';
    }
}
