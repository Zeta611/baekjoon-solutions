n = input()
min_op = [0] * n

for m in xrange(2, n + 1):
    if m % 2 == 0 and m % 3 == 0:
        min_op[m - 1] = min(min_op[m - 2], min_op[m / 2 - 1], min_op[m / 3 - 1]) + 1
    elif m % 2 == 0:
        min_op[m - 1] = min(min_op[m - 2], min_op[m / 2 - 1]) + 1
    elif m % 3 == 0:
        min_op[m - 1] = min(min_op[m - 2], min_op[m / 3 - 1]) + 1
    else:
        min_op[m - 1] = min_op[m - 2] + 1

print min_op[-1]
