import sys


def merge_sort_iter(a):
    n = len(a)
    i = 2
    while i < n * 2:
        for j in xrange(0, n, i):
            llim = min(j + i / 2, n) - j
            rlim = min(j + i, n) - (j + i / 2)
            left = a[j:j + llim]
            right = a[j + i / 2:j + i / 2 + rlim]
            ileft = iright = 0
            k = j
            while ileft < llim or iright < rlim:
                if iright >= rlim or (ileft < llim and left[ileft] < right[iright]):
                    a[k] = left[ileft]
                    ileft += 1
                else:
                    a[k] = right[iright]
                    iright += 1
                k += 1
        i *= 2
    return a


n = input()
sorted = merge_sort_iter([int(sys.stdin.readline().strip()) for _ in range(n)])

s = 0.
cnt = [0] * 8001
for e in sorted:
    s += e
    cnt[e] += 1
m = 0
argm = 0
for i in xrange(-4000, 4001):
    if cnt[i] > m:
        m = cnt[i]
        argm = i
second = False
for i in xrange(-4000, 4001):
    if cnt[i] == m:
        if second:
            argm = i
            break
        second = True

print int(round(s / n))
print sorted[n / 2]
print argm
print sorted[-1] - sorted[0]
