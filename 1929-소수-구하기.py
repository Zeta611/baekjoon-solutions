m, n = map(int, raw_input().split())
sieve = [1] * n
sieve[0] = 0
for p in xrange(2, n + 1):
    if sieve[p - 1]:
        if m <= p:
            print p
        for i in xrange(p ** 2, n + 1, p):
            sieve[i - 1] = 0
