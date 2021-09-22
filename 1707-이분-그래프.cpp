#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

constexpr int N{20'000};

using AdjList = std::vector<std::vector<int>>;

bool bipartite(const AdjList &adj_list)
{
    std::queue<int> q;

    char parity[N + 1];
    memset(parity, -1, sizeof parity);

    for (int u{1}; u < adj_list.size(); ++u) {
        if (parity[u] != -1) {
            continue;
        }

        parity[u] = true;
        q.push(u);

        while (!q.empty()) {
            u = q.front();
            q.pop();

            for (const int v : adj_list[u]) {
                if (parity[v] == -1) {
                    parity[v] = !parity[u];
                    q.push(v);
                } else if (parity[v] == parity[u]) {
                    return false;
                }
            }
        }
    }

    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k;
    std::cin >> k;

    while (k--) {
        int v, e;
        std::cin >> v >> e;
        AdjList adj_list(v + 1, AdjList::value_type());

        for (int i = 0; i < e; ++i) {
            int u, w;
            std::cin >> u >> w;
            adj_list[u].push_back(w);
            adj_list[w].push_back(u);
        }

        std::cout << (bipartite(adj_list) ? "YES\n" : "NO\n");
    }
}
