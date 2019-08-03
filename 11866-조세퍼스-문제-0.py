n, m = map(int, raw_input().split())
c, v, i = range(1, n + 1), [], 0
while c:
    i += 1
    if i % m == 0:
        v.append(c.pop(0))
    else:
        c.append(c.pop(0))
print "<" + str(v)[1:-1] + ">"
