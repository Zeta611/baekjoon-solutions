N, Q1, Q2 = map(int, raw_input().split())
a = map(int, raw_input().split())
for i in xrange(1, N):
    a[i] += a[i - 1]
b = [None] * Q1
i = 0
for _ in xrange(Q1 + Q2):
    query = map(int, raw_input().split())
    if query[0] == 1:
        n, m = query[1], query[2]
        if n >= 2:
            cnt = a[m - 1] - a[n - 2]
        else:
            cnt = a[m - 1]
        for p in b:
            if p is None:
                break
            s, e, l = p
            cnt += max(0, min(e, m) - max(s, n) + 1) * l
        print cnt
    else:
        b[i] = (query[1], query[2], query[3])
        i += 1
