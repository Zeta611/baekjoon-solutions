def gcd(a, b):
    if a < b:
        a, b = b, a
    while b:
        a, b = b, a % b
    return a


print '1' * reduce(gcd, map(int, raw_input().split()))
