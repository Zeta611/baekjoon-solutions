#include <iostream>
#include <vector>

std::vector<int> adj_list[101];
bool visited[101];

int dfs(int u = 1)
{
    if (visited[u]) {
        return 0;
    }
    visited[u] = true;

    int cnt{1};
    for (int v : adj_list[u]) {
        cnt += dfs(v);
    }
    return cnt;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int v, e;
    std::cin >> v >> e;
    while (e--) {
        int u, v;
        std::cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    std::cout << dfs() - 1 << '\n';
}
