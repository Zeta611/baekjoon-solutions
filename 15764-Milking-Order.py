# Olympiad > USA Computing Olympiad > 2017-2018 Season > USACO 2018 US Open Contest > Bronze 2
header = raw_input().split()
n, m, k = map(int, header)
hierarchy = map(int, raw_input().split())
order = [raw_input() for _ in range(k)]
for i in range(k):
    order[i] = map(int, order[i].split())
pos_stat = [None] * n
cow_stat = [None] * n
for pair in order:
    pos_stat[pair[1] - 1], cow_stat[pair[0] - 1] = pair

earliest = None
for pos_one in range(1, n + 1):
    if pos_stat[pos_one - 1]:
        continue
    cow_try = cow_stat[:]
    pos_try = pos_stat[:]
    cow_try[0] = pos_one
    pos_try[pos_one - 1] = 1
    cur_pos = 1
    flag = False
    for cow in hierarchy:
        if cow_try[cow - 1]:
            if cur_pos > cow_try[cow - 1]:
                flag = True
                break
            cur_pos = cow_try[cow - 1] + 1
        else:
            while cur_pos <= n and pos_try[cur_pos - 1]:
                cur_pos += 1
            if cur_pos > n:
                flag = True
                break
            cow_try[cow - 1] = cur_pos
            pos_try[cur_pos - 1] = cow
            cur_pos += 1
    if flag:
        continue
    if earliest is None or earliest > pos_one:
        earliest = pos_one
print earliest
