n, k = map(int, input().split())
price = [0] * n
for i in range(n):
    price[i] = int(input())

dp = [1] + [0] * k

for i in range(n):
    for j in range(k + 1):
        if j - price[i] >= 0:
            dp[j] = dp[j] + dp[j - price[i]]

print(dp[-1])

# f(n, k): Making k using price[0] ~ price[n - 1]
# f(n, k) = 1 if k == 0,
#           0 else if n == 0,
#           f(n - 1, k) + f(n, k - price[n - 1])  otherwise.
