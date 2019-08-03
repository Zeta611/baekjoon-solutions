def combination_nlgp(n, r, p):
    factorial = [1] * (n + 1)
    for i in xrange(2, n + 1):
        factorial[i] = (factorial[i - 1] * i) % p
    exp = p - 2
    base = factorial[n]
    res = 1
    while exp:
        if exp % 2:
            res = (res * base) % p
        base = (base ** 2) % p
        exp /= 2
    factorial_inv = [1] * n + [res]
    for i in xrange(n - 1, -1, -1):
        factorial_inv[i] = (factorial_inv[i + 1] * (i + 1)) % p
    return (factorial[n] * factorial_inv[r] * factorial_inv[n - r]) % p


N, K = map(int, raw_input().split())
print combination_nlgp(N, K, 1000000007)
