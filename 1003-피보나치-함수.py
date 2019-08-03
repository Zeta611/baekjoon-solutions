for _ in range(input()):
    n = input()
    dp = [None] * (n + 1)
    dp[0] = (1, 0)
    if n > 0:
        dp[1] = (0, 1)
    for i in range(2, n + 1):
        dp[i] = (dp[i - 1][0] + dp[i - 2][0], dp[i - 1][1] + dp[i - 2][1])
    print dp[n][0], dp[n][1]
