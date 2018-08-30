def gcd(a, b):
    if a < b:
        a, b = b, a
    while b:
        a, b = b, a % b
    return a


def lcm(a, b):
    return a * b / gcd(a, b)


for _ in xrange(input()):
    print reduce(lcm, map(int, raw_input().split()))
