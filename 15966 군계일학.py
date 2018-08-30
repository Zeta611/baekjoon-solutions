n = input()
a = map(int, raw_input().split())
b = [1] * n
lookup = {a[0]: 0}
m = 1
for i in xrange(1, n):
    if a[i] - 1 in lookup:
        b[i] = b[lookup[a[i] - 1]] + 1
    else:
        b[i] = 1
    if b[i] > m: m = b[i]
    lookup[a[i]] = i
print m
