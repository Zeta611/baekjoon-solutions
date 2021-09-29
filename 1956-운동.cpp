#include <algorithm>
#include <iostream>

constexpr unsigned INF{400 * 399 * 10'000 + 1};
unsigned dist[401][401];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int v, e;
    std::cin >> v >> e;
    for (int i{1}; i <= v; ++i) {
        for (int j{1}; j <= v; ++j) {
            dist[i][j] = i == j ? 0 : INF;
        }
    }
    while (e--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        dist[a][b] = c;
    }

    // Floyd-Warshall
    for (int k{1}; k <= v; ++k) {
        for (int i{1}; i <= v; ++i) {
            for (int j{1}; j <= v; ++j) {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    unsigned min_d{INF};
    for (int i{1}; i < v; ++i) {
        for (int j{i + 1}; j <= v; ++j) {
            min_d = std::min(min_d, dist[i][j] + dist[j][i]);
        }
    }

    if (min_d < INF) {
        std::cout << min_d << '\n';
    } else {
        std::cout << "-1\n";
    }
}
