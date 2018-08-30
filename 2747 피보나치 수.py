n = input()
fibonacci = [1] * n
for i in range(2, n):
    fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2]
print fibonacci[n - 1]
