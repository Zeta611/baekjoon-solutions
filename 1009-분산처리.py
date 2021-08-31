n = int(input())
for _ in range(n):
    a, b = map(int, input().split())
    power = 1
    while b:
        if b % 2:
            power = power * a
            power %= 10
        a = a * a
        a %= 10
        b //= 2
    print(10 if power == 0 else power)
