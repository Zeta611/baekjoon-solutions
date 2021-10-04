#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using AdjList = std::vector<std::vector<std::tuple<int, int, int>>>;

int min_time(const AdjList &adj_list, int lim)
{
    std::vector<std::vector<int>> dist(size(adj_list),
                                       std::vector<int>(lim + 1, -1));
    std::priority_queue<std::tuple<int, int, int>> pq;
    pq.emplace(0, 0, 1);
    dist[1][0] = 0;

    while (!empty(pq)) {
        auto [u_dist, u_cost, u]{pq.top()};
        pq.pop();
        u_dist = -u_dist;
        u_cost = -u_cost;

        if (dist[u][u_cost] != -1 && u_dist > dist[u][u_cost]) {
            continue;
        }
        if (u_cost > lim) {
            continue;
        }
        if (u == size(adj_list) - 1) {
            return u_dist;
        }

        for (const auto &[v, c, d] : adj_list[u]) {
            const int nc{c + u_cost};
            const int nd{d + u_dist};
            if (nc <= lim && (dist[v][nc] == -1 || nd < dist[v][nc])) {
                for (int i{nc + 1}; i <= lim; ++i) {
                    if (dist[v][i] == -1 || dist[v][i] > nd) {
                        dist[v][i] = nd;
                    } else {
                        break;
                    }
                }

                dist[v][nc] = nd;
                pq.emplace(-nd, -nc, v);
            }
        }
    }

    return -1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        int n, m, k;
        std::cin >> n >> m >> k;
        AdjList adj_list(n + 1);
        while (k--) {
            int u, v, c, d;
            std::cin >> u >> v >> c >> d;
            adj_list[u].emplace_back(v, c, d);
        }

        if (const int t{min_time(adj_list, m)}; t != -1) {
            std::cout << t << '\n';
        } else {
            std::cout << "Poor KCM\n";
        }
    }
}
