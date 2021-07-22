#include <iostream>
#include <queue>

constexpr long ROOM_MAX{50000 + 1};
constexpr long PATH_MAX{2 * 500000};
constexpr long TIME_MAX{PATH_MAX / 2 * 100};

long _nc{0};
struct PathNode {
    long end;
    long time;
    PathNode *next;
} _nodes[PATH_MAX], *rooms[ROOM_MAX], *rev_rooms[ROOM_MAX];

inline PathNode *alloc(long end, long time, PathNode *next)
{
    PathNode *node{&_nodes[_nc++]};
    *node = {end, time, next};
    return node;
}

void init(long room_cnt, long path_cnt)
{
    _nc = 0;
    for (long i{1}; i <= room_cnt; ++i) {
        rooms[i] = rev_rooms[i] = nullptr;
    }
    while (path_cnt--) {
        long begin, end, time;
        std::cin >> begin >> end >> time;
        rooms[begin] = alloc(end, time, rooms[begin]);
        rev_rooms[end] = alloc(begin, time, rev_rooms[end]);
    }
}

void dijkstra(long src, const PathNode *const *vertices, long *time, long cnt)
{
    const auto cmp = [time](long a, long b) { return time[a] > time[b]; };
    std::priority_queue<long, std::vector<long>, decltype(cmp)> pqueue(cmp);
    pqueue.push(src);

    static bool visited[ROOM_MAX];
    for (long i{1}; i <= cnt; ++i) {
        visited[i] = false;
        time[i] = TIME_MAX;
    }
    time[src] = 0;

    while (!pqueue.empty()) {
        const long curr{pqueue.top()};
        pqueue.pop();

        for (auto neighb = vertices[curr]; neighb; neighb = neighb->next) {
            const long v{neighb->end};
            if (visited[v]) {
                continue;
            }
            const long tentative{time[curr] + neighb->time};
            if (tentative < time[v]) {
                time[v] = tentative;
                pqueue.push(v);
            }
        }
        visited[curr] = true;
    }
}

long bottle_neck(long room_cnt, long id)
{
    static long time[ROOM_MAX], rev_time[ROOM_MAX];
    dijkstra(id, rooms, time, room_cnt);
    dijkstra(id, rev_rooms, rev_time, room_cnt);

    long max_t{0};
    for (long i{1}; i <= room_cnt; ++i) {
        const long t{time[i] + rev_time[i]};
        if (max_t < t) {
            max_t = t;
        }
    }
    return max_t;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long room_cnt, path_cnt, id;
    std::cin >> room_cnt >> path_cnt >> id;
    init(room_cnt, path_cnt);
    std::cout << bottle_neck(room_cnt, id) << '\n';
    return 0;
}
