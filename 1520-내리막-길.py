import sys
sys.setrecursionlimit(1200)

M, N = map(int, input().split())
table = [None] * M
for i in range(M):
    table[i] = list(map(int, input().split()))


def path_case(i, j, memo=dict()):
    val = table[i][j]
    if (i, j) in memo:
        return memo[(i, j)]
    path = 0
    if (i, j) == (0, 0):
        if (N == 1 or val < table[0][1]) and (M == 1 or val < table[1][0]):
            if N == M == 1:
                path = 1
            else:
                path = 0
        else:
            path = 1
    elif (i, j) == (0, N - 1):
        if val < table[0][N - 2]:
            path = path_case(0, N - 2, memo)
        else:
            path = 0
    elif (i, j) == (M - 1, 0):
        if val < table[M - 2][0]:
            path = path_case(M - 2, 0, memo)
        else:
            path = 0
    elif (i, j) == (M - 1, N - 1):
        if val < table[M - 1][N - 2]:
            path += path_case(M - 1, N - 2, memo)
        if val < table[M - 2][N - 1]:
            path += path_case(M - 2, N - 1, memo)
    elif i == 0:
        if val < table[0][j - 1]:
            path += path_case(0, j - 1, memo)
        if M > 1 and val < table[1][j]:
            path += path_case(1, j, memo)
    elif j == 0:
        if val < table[i - 1][0]:
            path += path_case(i - 1, 0, memo)
        if N > 1 and val < table[i][1]:
            path += path_case(i, 1, memo)
    elif i == M - 1:
        if val < table[M - 2][j]:
            path += path_case(M - 2, j, memo)
        if val < table[M - 1][j - 1]:
            path += path_case(M - 1, j - 1, memo)
    elif j == N - 1:
        if val < table[i][N - 2]:
            path += path_case(i, N - 2, memo)
        if val < table[i - 1][N - 1]:
            path += path_case(i - 1, N - 1, memo)
    else:
        if val < table[i][j - 1]:
            path += path_case(i, j - 1, memo)
        if val < table[i][j + 1]:
            path += path_case(i, j + 1, memo)
        if val < table[i - 1][j]:
            path += path_case(i - 1, j, memo)
        if val < table[i + 1][j]:
            path += path_case(i + 1, j, memo)
    memo[(i, j)] = path
    return path


print(path_case(M - 1, N - 1))
