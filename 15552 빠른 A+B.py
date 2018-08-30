import sys

input()
for l in sys.stdin:
    print sum(map(int, l.split()))
