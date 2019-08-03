def f(i, j):
    if i == j == 0:
        return 1
    k = max(abs(i), abs(j))
    if j == k and i < k:
        return 4 * k ** 2 - 3 * k + 1 - i
    elif i == -k and j < k:
        return 4 * k ** 2 - k + 1 - j
    elif j == -k and i > -k:
        return 4 * k ** 2 + k + 1 + i
    else:
        return 4 * k ** 2 + 3 * k + 1 + j


r1, c1, r2, c2 = map(int, raw_input().split())
table = [[str(f(i, j)) for j in xrange(c1, c2 + 1)] for i in xrange(r1, r2 + 1)]
m = table[0][0]
for line in table:
    for e in line:
        if len(e) > len(m):
            m = e
for line in table:
    for e in line:
        print " " * (len(m) - len(e)) + e,
    print
