n = int(input())

for i in range(n):
    if n == 1:
        print("*")
        break
    print(" ".join(["*"] * (n // 2 + n % 2)))
    print(" " + " ".join(["*"] * (n // 2)))
