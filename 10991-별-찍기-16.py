n = int(input())

for i in range(1, n + 1):
    print(" " * (n - i), end="")
    for j in range(1, 2 * i):
        if j % 2 == 0:
            print(" ", end="")
        else:
            print("*", end="")
    print()
