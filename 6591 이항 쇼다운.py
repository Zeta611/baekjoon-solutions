# Contest > University of Ulm Local Contest > University of Ulm Local Contest 1997 B
def combination_dp(n, r):
    dp = [[0] * (r + 1) for _ in xrange(n + 1)]
    for i in xrange(n + 1):
        for j in xrange(r + 1):
            if i == j or j == 0:
                dp[i][j] = 1
            elif i > j:
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
    return dp[n][r]


def combination_n(n, r, p):
    factorial = [1] * (n + 1)
    factorial_inv = [1] * (n + 1)
    inv = [1] * (n + 1)
    for i in xrange(2, n + 1):
        factorial[i] = (factorial[i - 1] * i) % p
        inv[i] = - (p / i) * inv[p % i]
        factorial_inv[i] = (factorial_inv[i - 1] * inv[i]) % p
    return (factorial[n] * factorial_inv[r] * factorial_inv[n - r]) % p


while 1:
    n, k = map(int, raw_input().split())
    if n == k == 0:
        break
    if k > n - k:
        k = n - k
    if k == 0:
        print 1
    elif k == 1:
        print n
    elif k == 2:
        print n * (n - 1) / 2
    elif k == 3:
        print n * (n - 1) * (n - 2) / 6
    else:
        # print combination_dp(n, k)
        print combination_n(n, k, 2147483659)
