import math

for _ in range(input()):
    x, y = map(float, raw_input().split())
    m = int((y - x) ** .5)
    print int(2 * m + math.ceil((y - x - m ** 2) / m)) - 1
