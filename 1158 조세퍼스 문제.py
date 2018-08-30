from collections import deque

n, m = map(int, raw_input().split())
c, v, i = deque(range(1, n + 1)), [], 0
while c:
    i += 1
    a = c.popleft()
    if i % m == 0:
        v.append(a)
    else:
        c.append(a)
print "<" + str(v)[1:-1] + ">"
