#include <array>
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
constexpr int MAX_WEIGHT{1000};
constexpr int INF{200'000 * MAX_WEIGHT};

template <std::size_t N>
std::array<int, N> dijkstra(const AdjList &adj_list, int src,
                            std::array<int, N> dest)
{
    std::vector<int> dist(adj_list.size(), INF);
    dist[src] = 0;

    Heap<int, 800, std::greater<int>> heap;
    for (int i{1}; i < adj_list.size(); ++i) {
        heap.push(i, dist[i]);
    }

    while (!heap.empty()) {
        const int u{heap.top()};
        heap.pop();

        for (const auto &[v, w] : adj_list[u]) {
            if (!heap.contains(v)) {
                continue;
            }
            if (dist[v] > dist[u] + w) {
                heap.update_key(v, dist[v] = dist[u] + w);
            }
        }
    }

    std::array<int, N> d;
    for (int i{0}; i < dest.size(); ++i) {
        d[i] = dist[dest[i]];
    }
    return d;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, e;
    std::cin >> n >> e;

    AdjList adj_list(n + 1, AdjList::value_type());

    while (e--) {
        int u, v, w;
        std::cin >> u >> v >> w;
        adj_list[u].emplace_back(v, w);
        adj_list[v].emplace_back(u, w);
    }

    int v1, v2;
    std::cin >> v1 >> v2;

    const auto [one_v1, n_v1, v1_v2]{dijkstra<3>(adj_list, v1, {1, n, v2})};
    const auto [one_v2, n_v2]{dijkstra<2>(adj_list, v2, {1, n})};

    int min_d{INF};
    for (int d : {one_v1 + v1_v2 + n_v2, one_v1 + 2 * v1_v2 + n_v1,
                  one_v2 + v1_v2 + n_v1, one_v2 + 2 * v1_v2 + n_v2}) {
        if (d >= 0 && d < min_d) {
            min_d = d;
        }
    }

    if (min_d == INF) {
        std::cout << "-1\n";
    } else {
        std::cout << min_d << '\n';
    }
}
