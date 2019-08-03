from math import log

N = 500000
bound = int(N * log(N * log(N))) + 1
k = int(raw_input())
sieve = [1] * bound
sieve[0] = 0
dp = [0] * bound
for p in xrange(2, bound + 1):
    dp[p - 1] = dp[p - 2]
    if sieve[p - 1]:
        dp[p - 1] += 1
        if dp[p - 1] == k:
            print p
            break
        for i in xrange(p ** 2, bound + 1, p):
            sieve[i - 1] = 0
