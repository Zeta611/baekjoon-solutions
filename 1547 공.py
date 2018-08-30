cup = [True, False, False]
for _ in xrange(input()):
    a, b = map(int, raw_input().split())
    cup[a - 1], cup[b - 1] = cup[b - 1], cup[a - 1]
print cup.index(True) + 1
