# ACM-ICPC > Regionals > Asia > Japan > Domestic Contest > 2011 Domestic Contest A
sieve = [1] * 246912
sieve[0] = 0
dp = [0] * 246912
for p in xrange(2, 246913):
    dp[p - 1] = dp[p - 2]
    if sieve[p - 1]:
        dp[p - 1] += 1
        for i in xrange(p ** 2, 246913, p):
            sieve[i - 1] = 0

while 1:
    n = input()
    if n == 0:
        break
    print dp[2 * n - 1] - dp[n - 1]
