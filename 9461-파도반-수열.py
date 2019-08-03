# ACM-ICPC > Regionals > Asia > Korea > Asia Regional - Daejeon 2013 G
import sys

T = int(sys.stdin.readline())
tc = [0] * T
m = 0
for i in xrange(T):
    tc[i] = int(sys.stdin.readline())
    if tc[i] > m:
        m = tc[i]
P = [0, 1, 1, 1, 2] + [-1] * max(m - 4, 0)
for i in xrange(5, m + 1):
    P[i] = P[i - 5] + P[i - 1]
for N in tc:
    print P[N]
