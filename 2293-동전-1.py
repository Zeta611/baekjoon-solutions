n, k = map(int, raw_input().split())
coin = [0] * (n + 1)
for i in range(1, n + 1):
    coin[i] = input()

dp = [[1] + [0] * k for _ in xrange(n + 1)]

for i in xrange(1, n + 1):
    for j in xrange(k + 1):
        if coin[i] > j:
            dp[i][j] = dp[i - 1][j]
        else:
            dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i]]
print dp[-1][-1]

# dp[i][j]: Making j using 1 ~ i coins
# dp[i][j] = dp[i - 1][j]                           if coin[i] > j
# dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i]] + 1  if coin[i] <= j
