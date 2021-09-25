#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <ranges>
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

constexpr int INF{50'000 * 1000 + 1};
using AdjList = std::vector<std::vector<std::pair<int, int>>>;
std::vector<int> dijkstra(int s, const AdjList &adj_list)
{
    std::vector<int> dist(adj_list.size(), INF);
    dist[s] = 0;

    Heap<int, 2000, std::greater<int>> pq;
    for (int i{1}; i < adj_list.size(); ++i) {
        pq.push(i, dist[i]);
    }

    while (!pq.empty()) {
        const int u{pq.top()};
        pq.pop();

        for (const auto &[v, w] : adj_list[u]) {
            if (dist[v] > dist[u] + w) {
                pq.update_key(v, dist[v] = dist[u] + w);
            }
        }
    }

    return dist;
}

std::vector<int> cands(int s, int g, int h, const std::vector<int> &dst,
                       const AdjList &adj_list)
{
    const auto dist_s{dijkstra(s, adj_list)};
    const auto dist_g{dijkstra(g, adj_list)};
    const auto dist_h{dijkstra(h, adj_list)};

    const int sh{dist_s[h]};
    const int sg{dist_s[g]};
    const int gh{dist_g[h]};

    std::vector<int> ret;
    std::ranges::copy_if(dst, back_inserter(ret), [&](int d) {
        return std::min(sh + dist_g[d], sg + dist_h[d]) == dist_s[d] - gh;
    });
    std::ranges::sort(ret);
    return ret;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int c;
    std::cin >> c;
    while (c--) {
        int n, m, t, s, g, h;
        std::cin >> n >> m >> t >> s >> g >> h;

        AdjList adj_list(n + 1, AdjList::value_type());
        for (int i{0}; i < m; ++i) {
            int a, b, d;
            std::cin >> a >> b >> d;
            adj_list[a].emplace_back(b, d);
            adj_list[b].emplace_back(a, d);
        }

        std::vector<int> dst;
        copy_n(std::istream_iterator<int>(std::cin), t, back_inserter(dst));

        std::ranges::copy(cands(s, g, h, dst, adj_list),
                          std::ostream_iterator<int>(std::cout, " "));
    }
}
