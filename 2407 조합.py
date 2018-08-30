n, m = map(int, raw_input().split())
dp = [[0] * (m + 1) for _ in xrange(n + 1)]
for i in xrange(n + 1):
    for j in xrange(m + 1):
        if i == j or j == 0:
            dp[i][j] = 1
        elif i > j:
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
print dp[n][m]
