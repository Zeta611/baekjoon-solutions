#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>

template <class T, std::size_t MAX_SIZE, class Compare = std::less<T>>
class Heap
{
    static_assert(MAX_SIZE < std::numeric_limits<std::size_t>::max());

    std::size_t size{0};
    std::pair<std::size_t, T> container[MAX_SIZE];
    // -1 will be converted to the maximum value for std::size_t.
    std::vector<std::size_t> id_table = decltype(id_table)(MAX_SIZE + 1, -1);
    Compare cmp;

    static inline std::size_t left(std::size_t i) { return (i << 1) + 1; }
    static inline std::size_t right(std::size_t i) { return (i + 1) << 1; }
    static inline std::size_t parent(std::size_t i) { return (i - 1) >> 1; }

    void heapify(std::size_t i)
    {
        const std::size_t l{left(i)};
        const std::size_t r{right(i)};

        std::size_t m{
            l < size && cmp(container[i].second, container[l].second) ? l : i};
        if (r < size && cmp(container[m].second, container[r].second)) {
            m = r;
        }

        if (m != i) {
            std::swap(container[m], container[i]);
            id_table[container[m].first] = m;
            id_table[container[i].first] = i;
            heapify(m);
        }
    }

  public:
    inline bool empty() const { return !size; }
    inline T top() const { return container[0].first; }
    inline bool contains(std::size_t id) const { return id_table[id] != -1; }

    void update_key(std::size_t id, const T &x)
    {
        std::size_t i{id_table[id]};
        container[i] = {id, x};

        std::size_t p{parent(i)};
        while (i && cmp(container[p].second, container[i].second)) {
            std::swap(container[p], container[i]);
            id_table[container[p].first] = p;
            id_table[container[i].first] = i;
            i = p;
            p = parent(i);
        }
    }

    void push(std::size_t id, const T &x)
    {
        id_table[id] = size++;
        update_key(id, x);
    }

    void pop()
    {
        id_table[container[0].first] = -1;
        container[0] = container[--size];
        id_table[container[0].first] = 0;
        heapify(0);
    }

    Heap(const Compare &cmp = {}) : cmp{cmp} {}
};

using AdjList = std::vector<std::vector<std::pair<int, int>>>;
constexpr int MAX_WEIGHT{10};
constexpr int INF{std::numeric_limits<int>::max() - MAX_WEIGHT - 1};

std::vector<int> dijkstra(int src, const AdjList &adj_list)
{
    Heap<int, 20'000, std::greater<int>> heap;

    std::vector<int> dist(adj_list.size(), INF);
    dist[src] = 0;
    for (int i{1}; i < adj_list.size(); ++i) {
        heap.push(i, dist[i]);
    }

    while (!heap.empty()) {
        const int u{heap.top()};
        heap.pop();

        for (auto &[v, w] : adj_list[u]) {
            if (!heap.contains(v)) {
                continue;
            }
            if (dist[v] > dist[u] + w) {
                heap.update_key(v, dist[v] = dist[u] + w);
            }
        }
    }

    return dist;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int v, e;
    std::cin >> v >> e;

    AdjList adj_list(v + 1);

    int src;
    std::cin >> src;

    for (int i{0}; i < e; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj_list[u].emplace_back(v, w);
    }

    const auto min_dist{dijkstra(src, adj_list)};

    for (int i{1}; i <= v; ++i) {
        if (min_dist[i] == INF) {
            std::cout << "INF\n";
        } else {
            std::cout << min_dist[i] << '\n';
        }
    }
}
