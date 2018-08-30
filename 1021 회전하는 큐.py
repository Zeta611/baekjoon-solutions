from collections import deque

n, m = map(int, raw_input().split())
extract = deque(map(int, raw_input().split()))
que = deque(range(1, n + 1))
cnt = 0
while extract:
    to_find = extract.popleft()
    i = 0
    while que[i] != to_find:
        i += 1
    if i < len(que) - i:
        for _ in range(i):
            que.append(que.popleft())
        cnt += i
        que.popleft()
    else:
        for _ in range(len(que) - i):
            que.appendleft(que.pop())
        cnt += len(que) - i
        que.popleft()
print cnt
