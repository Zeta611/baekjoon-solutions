from collections import deque

n, m, v = map(int, raw_input().split())
graph = dict()

for i in range(1, n + 1):
    graph[i] = []
for _ in range(m):
    vertex = map(int, raw_input().split())
    graph[vertex[0]].append(vertex[1])
    graph[vertex[1]].append(vertex[0])
for i in range(1, n + 1):
    graph[i].sort()


def dfs(graph, start):
    visited = set()
    stack = [start]
    while stack:
        current = stack.pop()
        if current not in visited:
            visited.add(current)
            for connected in graph[current][::-1]:
                if connected not in visited:
                    stack.append(connected)
            print current,
    print


def bfs(graph, start):
    visited = set()
    que = deque([start])
    while que:
        current = que.popleft()
        if current not in visited:
            visited.add(current)
            for connected in graph[current]:
                if connected not in visited:
                    que.append(connected)
            print current,
    print


dfs(graph, v)
bfs(graph, v)
