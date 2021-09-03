#include <iostream>
#include <queue>
#include <vector>

std::vector<int> adj_list[1001];
bool visited[1001];
std::queue<int> q;

void bfs(int src)
{
    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        const int v{q.front()};
        q.pop();

        for (int u : adj_list[v]) {
            if (visited[u]) {
                continue;
            }
            visited[u] = true;
            q.push(u);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    while (m--) {
        int u, v;
        std::cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int cnt{0};
    for (int v{1}; v <= n; ++v) {
        if (visited[v]) {
            continue;
        }
        ++cnt;
        bfs(v);
    }

    std::cout << cnt << '\n';
}
