# ACM-ICPC > Regionals > Asia > Korea > Nationwide Internet Competition > Asia Regional - Daejeon Nationalwide Internet Competition 2015 F
import sys


def cost_interval(i, j):
    if i == 0:
        return cost_accumulate[j - 1]
    return cost_accumulate[j - 1] - cost_accumulate[i - 1]


for _ in xrange(int(sys.stdin.readline())):
    K = int(sys.stdin.readline())
    cost = map(int, sys.stdin.readline().split())
    cost_accumulate = [cost[0]] + [0] * (K - 1)
    for i in xrange(1, K):
        cost_accumulate[i] = cost_accumulate[i - 1] + cost[i]
    dp = [[0] * (K + 1) for _ in xrange(K)]
    a = [[0] * (K + 1) for _ in xrange(K)]
    for diff in xrange(2, K + 1):
        for i in xrange(K - diff + 1):
            j = i + diff
            if diff == 2:
                dp[i][j] = cost[i] + cost[i + 1]
                a[i][j] = i + 1
            else:
                m = sys.maxint
                # for k in xrange(i + 1, j):
                for k in xrange(a[i][j - 1], a[i + 1][j] + 1):  # Knuth's optimization
                    c = dp[i][k] + dp[k][j]
                    if m > c:
                        m = c
                        a[i][j] = k
                dp[i][j] = m + cost_interval(i, j)
    print dp[0][K]
# 2
# 4
# 40 30 30 50
# 15
# 1 21 3 4 5 35 5 4 3 5 98 21 14 17 32