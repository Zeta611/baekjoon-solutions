import math

m = int(math.log(input() / 3, 2) + 1)


def f(n):
    if n == 1:
        return ["  *  ", " * * ", "*****"]
    p = f(n - 1)
    r = []
    m = len(p[0]) / 2 + 1
    for i in range(m):
        r.append(" " * m + p[i] + " " * m)
    for i in range(m, 2 * m):
        r.append(p[i % m] + " " + p[i % m])
    return r


for l in f(m):
    print l
