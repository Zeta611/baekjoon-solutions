N, L = map(int, raw_input().split())
v = N - L * (L - 1) / 2
while v % L != 0 and v >= 0 and L <= 100:
    L += 1
    v = N - L * (L - 1) / 2
if v < 0 or L > 100:
    print -1
else:
    a = v / L
    for n in xrange(a, a + L):
        print n,
