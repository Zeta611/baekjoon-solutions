# Contest > Croatian Open Competition in Informatics > COCI 2007/2008 > Contest #6 3
import sys


def divisor(n):
    d = []
    m = int(n ** .5)
    for i in xrange(2, m + 1):
        if n % i == 0:
            d.append(i)
            if i < m or m ** 2 != n:
                d.append(n / i)
    d.append(n)
    return sorted(d)


N = int(sys.stdin.readline())
numbers = [0] * N
m = 1
for i in xrange(N):
    numbers[i] = int(sys.stdin.readline())
numbers.sort()
div = divisor(numbers[-1] - numbers[0])
for M in div:
    residue = numbers[0] % M
    flag = True
    for i in xrange(1, N - 1):
        if numbers[i] % M != residue:
            flag = False
            break
    if flag:
        print M,
