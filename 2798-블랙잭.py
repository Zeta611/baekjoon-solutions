n, m = list(map(int, input().split()))
cards = list(map(int, input().split()))
max_ = 0
for i in range(n):
    for j in range(i + 1, n):
        for k in range(j + 1, n):
            sum_ = cards[i] + cards[j] + cards[k]
            if max_ < sum_ <= m:
                max_ = sum_
print(max_)
