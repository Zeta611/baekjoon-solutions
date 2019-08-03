def combination_rec(n, r):
    if r == 0 or r == n:
        return 1
    return combination_rec(n - 1, r - 1) + combination_rec(n - 1, r)


N, K = map(int, raw_input().split())
print combination_rec(N, K)
