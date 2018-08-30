import sys

n = [0] * 10001
r = xrange
for _ in r(input()):
    n[int(sys.stdin.readline().rstrip())] += 1
for i in r(10001):
    for _ in r(n[i]):
        print i
