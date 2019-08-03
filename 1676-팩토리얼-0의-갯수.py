cnt = 0
for n in xrange(1, input() + 1):
    while n % 5 == 0:
        cnt += 1
        n /= 5
print cnt
