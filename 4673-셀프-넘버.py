# ACM-ICPC > Regionals > North America > Mid-Central Regional > 1998 Mid-Central Regional Programming Contest D

Max = 10000
sieve = [1] * Max


def digit_sum(n):
    s = 0
    while n:
        s += n % 10
        n /= 10
    return s


for n in range(1, Max + 1):  # 0.00494849920273s average
    if sieve[n - 1]:
        print n
        n += digit_sum(n)
        while n <= Max and sieve[n - 1]:
            sieve[n - 1] = 0
            n += digit_sum(n)

# Inefficient implementation, 1.53934011459s average
# for n in range(1, Max + 1):
#     n += digit_sum(n)
#     while n <= Max:
#         sieve[n - 1] = 0
#         n += digit_sum(n)
#
# for i in range(Max):
#     if sieve[i]:
#         print i + 1

# Short coding
# r = range(10001)
# l = {i + sum(map(int, str(i))) for i in r}
# for e in sorted(set(r) - l):
#     print e
