s1 = raw_input()
s2 = raw_input()
n1 = len(s1)
n2 = len(s2)

dp = [[0] * (n2 + 1) for _ in xrange(n1 + 1)]
for i in xrange(1, n1 + 1):
    for j in xrange(1, n2 + 1):
        if s1[i - 1] == s2[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
        else:
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j])
print dp[-1][-1]
