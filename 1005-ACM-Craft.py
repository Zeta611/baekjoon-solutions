from collections import deque
import sys

sys.setrecursionlimit(10000)


# Fifth try using topological sort with indegree.
def min_time(graph, graph_rev, n, time, v):
    que = deque(set(range(1, n + 1)) - set(graph_rev))
    dp = time[:]
    while que:
        w = que.popleft()
        if w in graph:
            for connected in graph[w]:
                dp[connected - 1] = max(dp[connected - 1], dp[w - 1] + time[connected - 1])
                graph_rev[connected].remove(w)
                if len(graph_rev[connected]) == 0:
                    que.append(connected)
    return dp[v - 1]


for _ in xrange(int(sys.stdin.readline())):
    N, K = map(int, sys.stdin.readline().split())
    D = map(int, sys.stdin.readline().split())
    graph = {}
    graph_rev = {}
    for i in xrange(K):
        X, Y = map(int, sys.stdin.readline().split())
        if X in graph:
            graph[X].add(Y)
        else:
            graph[X] = {Y}
        if Y in graph_rev:
            graph_rev[Y].add(X)
        else:
            graph_rev[Y] = {X}
    W = int(sys.stdin.readline())
    print min_time(graph, graph_rev, N, D, W)

# Fourth try using topological sort with dp
# def min_time(graph, graph_rev, n, time, v):
#     stack = []
#     for w in xrange(1, n + 1):
#         if w not in graph:
#             stack.append((w, False))
#     visited = set()
#     dp = [0] * n
#     while stack:
#         w, is_parent = stack.pop()
#         if is_parent:
#             if w not in graph_rev:
#                 dp[w - 1] = time[w - 1]
#             else:
#                 dp[w - 1] = max([dp[connected - 1] for connected in graph_rev[w]]) + time[w - 1]
#             continue
#         if w not in visited:
#             visited.add(w)
#             stack.append((w, True))
#             if w in graph_rev:
#                 for w in graph_rev[w]:
#                     if w not in visited:
#                         stack.append((w, False))
#     return dp[v - 1]
#
#
# for _ in xrange(int(sys.stdin.readline())):
#     N, K = map(int, sys.stdin.readline().split())
#     D = map(int, sys.stdin.readline().split())
#     graph = set()
#     graph_rev = {}
#     for i in xrange(K):
#         X, Y = map(int, sys.stdin.readline().split())
#         graph.add(X)
#         if Y in graph_rev:
#             graph_rev[Y].add(X)
#         else:
#             graph_rev[Y] = {X}
#     W = int(sys.stdin.readline())
#     print min_time(graph, graph_rev, N, D, W)


# Third try using topological sort with recursion
# def dfs_rec(graph, n, v, time, visited=None, dp=None):
#     if visited is None:
#         visited = set()
#     if dp is None:
#         dp = [0] * n
#     visited.add(v)
#     if v in graph:
#         for w in graph[v] - visited:
#             if w in graph[v] - visited:
#                 dfs_rec(graph, n, w, time, visited, dp)
#     if v not in graph:
#         dp[v - 1] = time[v - 1]
#     else:
#         if v - 1 < n:
#             dp[v - 1] = max([dp[connected - 1] for connected in graph[v]]) + time[v - 1]
#     return visited, dp
#
#
# def min_time(graph, graph_rev, n, time, v):
#     sinks = set(graph_rev) - graph
#     graph_rev[n + 1] = sinks
#     dp = dfs_rec(graph_rev, n, n + 1, time)[1]
#     return dp[v - 1]
#
#
# for _ in xrange(int(sys.stdin.readline())):
#     N, K = map(int, sys.stdin.readline().split())
#     D = map(int, sys.stdin.readline().split())
#     graph = set()
#     graph_rev = {}
#     for i in xrange(K):
#         X, Y = map(int, sys.stdin.readline().split())
#         graph.add(X)
#         if Y in graph_rev:
#             graph_rev[Y].add(X)
#         else:
#             graph_rev[Y] = {X}
#     W = int(sys.stdin.readline())
#     print min_time(graph, graph_rev, N, D, W)

# Second try, success (memoization reverse DFS)
# def min_time(graph, time, v, memo):
#     if v in memo:
#         return memo[v]
#     if v not in graph:
#         return time[v - 1]
#     memo[v] = max([min_time(graph, time, connected, memo) for connected in graph[v]]) + time[v - 1]
#     return memo[v]
#
#
# for _ in xrange(input()):
#     raw_input()
#     N, K = map(int, raw_input().split())
#     raw_input()
#     D = map(int, raw_input().split())
#     raw_input()
#     graph_rev = {}
#     for i in xrange(K):
#         X, Y = map(int, raw_input().split())
#         raw_input()
#         if Y in graph_rev:
#             graph_rev[Y].add(X)
#         else:
#             graph_rev[Y] = {X}
#     W = input()
#     print min_time(graph_rev, D, W, {})

# First try, time exceeded
# def min_time(graph, time, v):
#     if v == 1:
#         return time[0]
#     return max(map(lambda x: min_time(graph, time, x), graph[v])) + time[v - 1]
#
#
# for _ in xrange(input()):
#     N, K = map(int, raw_input().split())
#     D = map(int, raw_input().split())
#     graph_rev = {}
#     for i in xrange(K):
#         X, Y = map(int, raw_input().split())
#         if Y in graph_rev:
#             graph_rev[Y].add(X)
#         else:
#             graph_rev[Y] = {X}
#     W = input()
#     print min_time(graph_rev, D, W)
