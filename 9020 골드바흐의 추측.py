# ACM-ICPC > Regionals > Asia > Korea > Nationwide Internet Competition > Asia Regional - Daejeon Nationalwide Internet Competition 2011 E
sieve = [1] * 10000
sieve[0] = 0
for p in xrange(2, 10001):
    if sieve[p - 1]:
        for i in xrange(p ** 2, 10001, p):
            sieve[i - 1] = 0
for _ in xrange(input()):
    n = input()
    for q in xrange(n / 2, n):
        if sieve[q - 1] and sieve[n - q - 1]:
            if q < n - q:
                print q, n - q
            else:
                print n - q, q
            break
