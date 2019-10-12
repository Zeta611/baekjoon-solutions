for _ in range(int(input())):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    d = ((x1 - x2)**2 + (y1 - y2)**2)**.5
    if (x1, y1, r1) == (x2, y2, r2):
        print(-1)
    elif d == abs(r1 - r2) or d == r1 + r2:
        print(1)
    elif abs(r1 - r2) < d < r1 + r2:
        print(2)
    else:
        print(0)
