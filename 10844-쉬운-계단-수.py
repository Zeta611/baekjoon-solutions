N = input()

dp = [[None] * 10 for _ in xrange(N)]
dp[0][0] = 0
for j in xrange(1, 10):
    dp[0][j] = 1
for i in xrange(1, N):
    dp[i][0] = dp[i - 1][1] % 1000000000
    dp[i][9] = dp[i - 1][8] % 1000000000
    for j in xrange(1, 9):
        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000
print sum(dp[N - 1]) % 1000000000
