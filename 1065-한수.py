c = 0
for i in range(1, input() + 1):
    if (lambda m: m % 10 + m / 100 == m / 10 % 10 * 2 and m / 10 % 10 > 0 or m / 100 == 0)(i):
        c += 1
print c
