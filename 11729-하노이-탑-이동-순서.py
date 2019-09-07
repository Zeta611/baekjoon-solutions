def hanoi(n, source, dest):
    if n == 1:
        print(source, dest)
        return
    hanoi(n - 1, source, 6 - source - dest)
    hanoi(1, source, dest)
    hanoi(n - 1, 6 - source - dest, dest)


n = int(input())
print(2 ** n - 1)
hanoi(n, 1, 3)
