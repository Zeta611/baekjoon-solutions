# ACM-ICPC > Regionals > Asia > Korea > Nationwide Internet Competition > Asia Regional - Daejeon Nationalwide Internet Competition 2013 E
import sys
from collections import deque

for _ in xrange(int(sys.stdin.readline())):
    N, L, k = map(int, sys.stdin.readline().split())
    time_to_id = dict()
    ant = deque()
    for i in xrange(N):
        pos, id = map(int, sys.stdin.readline().split())
        ant.append(id)
        direction = id / abs(id)
        if direction == 1:
            time = L - pos
        else:
            time = pos
        if time in time_to_id:
            time_to_id[time].add(direction)
        else:
            time_to_id[time] = {direction}
    cnt = 0
    for time in sorted(time_to_id):
        cnt += len(time_to_id[time])
        if k <= cnt:
            if len(time_to_id[time]) > 1:
                if k == cnt:
                    print max(ant.pop(), ant.popleft())
                else:
                    print min(ant.pop(), ant.popleft())
            else:
                if list(time_to_id[time])[0] == 1:
                    print ant.pop()
                else:
                    print ant.popleft()
            break
        for direction in time_to_id[time]:
            if direction == 1:
                ant.pop()
            else:
                ant.popleft()
