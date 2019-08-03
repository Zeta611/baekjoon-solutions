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
for e in merge_sort_iter([int(sys.stdin.readline().strip()) for _ in xrange(n)]):
    sys.stdout.write(str(e) + '\n')
