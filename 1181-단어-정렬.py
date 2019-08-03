import sys


def order(w1, w2):
    if len(w1) != len(w2):
        return len(w1) < len(w2)
    return w1 < w2


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
                if iright >= rlim or (ileft < llim and order(left[ileft], right[iright])):
                    a[k] = left[ileft]
                    ileft += 1
                else:
                    a[k] = right[iright]
                    iright += 1
                k += 1
        i *= 2
    return a


s = set()
for _ in range(input()):
    s.add(sys.stdin.readline().rstrip())
for word in merge_sort_iter(list(s)):
    print word
