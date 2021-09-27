#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

constexpr long long INF{6'000 * 10'000 + 1};

using AdjList = std::vector<std::vector<std::pair<int, int>>>;
std::vector<long long> bellman_ford(const AdjList &adj_list)
{
    std::vector<long long> dist(adj_list.size(), INF);
    dist[1] = 0;

    for (int i{1}; i < adj_list.size() - 1; ++i) {
        for (int u{1}; u < adj_list.size(); ++u) {
            for (const auto &[v, c] : adj_list[u]) {
                if (dist[u] < INF && dist[v] > dist[u] + c) {
                    dist[v] = dist[u] + c;
                }
            }
        }
    }

    for (int u{1}; u < adj_list.size(); ++u) {
        if (dist[u] == INF) {
            dist[u] = -1;
            continue;
        }
        for (const auto &[v, c] : adj_list[u]) {
            if (dist[v] > dist[u] + c) {
                dist[0] = 0;
                goto ret;
            }
        }
    }
ret:
    return dist;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    AdjList adj_list(n + 1, AdjList::value_type());
    while (m--) {
        int u, v, c;
        std::cin >> u >> v >> c;
        adj_list[u].emplace_back(v, c);
    }

    const auto dist{bellman_ford(adj_list)};
    if (!dist[0]) {
        std::cout << "-1\n";
    } else {
        copy(begin(dist) + 2, end(dist),
             std::ostream_iterator<int>(std::cout, "\n"));
    }
}
