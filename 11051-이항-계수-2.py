# memo = dict()
#
#
# def combination_memo(n, r):
#     if r == 0 or r == n:
#         return 1
#     if (n, r) in memo:
#         return memo[(n, r)]
#     memo[(n, r)] = combination_memo(n - 1, r - 1) + combination_memo(n - 1, r)
#     return memo[(n, r)]


def combination_memo(n, r):
    if r == 0 or r == n:
        return 1
    try:
        if (n, r) in combination_memo.memo:
            return combination_memo.memo[(n, r)]
        combination_memo.memo[(n, r)] = combination_memo(n - 1, r - 1) + combination_memo(n - 1, r)
    except AttributeError:
        combination_memo.memo = dict()
        combination_memo.memo[(n, r)] = combination_memo(n - 1, r - 1) + combination_memo(n - 1, r)
    return combination_memo.memo[(n, r)]


def combination_dp(n, r):
    dp = [[0] * (r + 1) for _ in xrange(n + 1)]
    for i in xrange(n + 1):
        for j in xrange(r + 1):
            if i == j or j == 0:
                dp[i][j] = 1
            elif i > j:
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
    return dp[n][r]


N, K = map(int, raw_input().split())
print combination_memo(N, K) % 10007
