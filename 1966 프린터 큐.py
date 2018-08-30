# ACM-ICPC > Regionals > Europe > Northwestern European Regional Contest > NWERC 2006 F
from collections import deque


def priority_check(priority_que):
    n = len(priority_que)
    for i in range(1, n):
        if priority_que[i] > priority_que[0]:
            return False
    return True


def priority_sort(priority_que, order_que):
    while not priority_check(priority_que):
        priority_que.append(priority_que.popleft())
        order_que.append(order_que.popleft())


for _ in range(input()):
    n, m = map(int, raw_input().split())
    priority_que = deque(map(int, raw_input().split()))
    order_que = deque(range(n))
    for i in range(n):
        priority_sort(priority_que, order_que)
        printed = order_que.popleft()
        priority_que.popleft()
        if printed == m:
            print i + 1
            break
