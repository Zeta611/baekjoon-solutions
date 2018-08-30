def sieve(n):
    sieve = [1] * n
    sieve[0] = 0
    for p in xrange(2, n + 1):
        if sieve[p - 1]:
            for i in xrange(p ** 2, n + 1, p):
                sieve[i - 1] = 0
    return sieve


N = input()
numbers = map(int, raw_input().split())
m = max(numbers)
s = sieve(m)
cnt = 0
for n in numbers:
    if s[n - 1]:
        cnt += 1
print cnt
