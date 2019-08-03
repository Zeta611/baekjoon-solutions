for _ in range(input()):
    k, n = input(), input()
    f = [[1] * n for _ in range(k + 1)]
    f[0] = range(1, n + 1)
    for i in range(1, k + 1):
        for j in range(1, n):
            f[i][j] = f[i][j - 1] + f[i - 1][j]
    print f[k][n - 1]
