import math

n = input()
k = int(math.ceil(((8 * n + 1) ** .5 - 1) / 2))
print "%d/%d" % (k * (k + 1) / 2 + 1 - n, n - k * (k - 1) / 2)[::(k % 2) * 2 - 1]
