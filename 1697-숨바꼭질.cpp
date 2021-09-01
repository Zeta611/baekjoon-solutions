#include <cstring>
#include <iostream>
#include <queue>

constexpr int MAX{100'000};

int dist[MAX + 1];
int bfs(int n, int k)
{
    std::memset(dist, -1, sizeof dist);
    dist[n] = 0;

    std::queue<int> q{{n}};
    while (!q.empty()) {
        const int m{q.front()};
        q.pop();

        if (m - 1 >= 0 && dist[m - 1] == -1) {
            q.push(m - 1);
            dist[m - 1] = dist[m] + 1;
        }
        if (m - 1 == k) {
            return dist[k];
        }

        if (m + 1 <= MAX && dist[m + 1] == -1) {
            q.push(m + 1);
            dist[m + 1] = dist[m] + 1;
        }
        if (m + 1 == k) {
            return dist[k];
        }

        if (m * 2 <= MAX && dist[m * 2] == -1) {
            q.push(m * 2);
            dist[m * 2] = dist[m] + 1;
        }
        if (m * 2 == k) {
            return dist[k];
        }
    }

    return -1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::cout << bfs(n, k) << '\n';
}
