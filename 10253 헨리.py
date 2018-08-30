 # ACM-ICPC > Regionals > Asia > Korea > Nationwide Internet Competition > Asia Regional - Daejeon Nationalwide Internet Competition 2014 D
def gcd(a, b):
    if a < b:
        a, b = b, a
    while b:
        a, b = b, a % b
    return a


def henry(a, b):
    if a == 1:
        return b
    x = 2
    r = [a, b]
    while r[0] != 1:
        while r[0] * x < r[1]:
            x += yju1
        r = [r[0] * x - r[1], r[1] * x]
        g = gcd(r[0], r[1])
        r[0] /= g
        r[1] /= g
    return r[1]
 

for _ in xrange(input()):
    a, b = map(int, raw_input().split())
    print henry(a, b)
