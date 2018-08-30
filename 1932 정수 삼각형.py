# Olympiad > International Olympiad in Informatics > IOI 1994 1
n = input()
utility = []
for _ in xrange(n):
    utility.append(map(int, raw_input().split()))

max_utility = utility[:]

for i in xrange(1, n):
    for j in xrange(i + 1):
        if j == 0:
            max_utility[i][j] = max_utility[i - 1][j] + utility[i][j]
        elif j == i:
            max_utility[i][j] = max_utility[i - 1][j - 1] + utility[i][j]
        else:
            max_utility[i][j] = max(max_utility[i - 1][j - 1], max_utility[i - 1][j]) + utility[i][j]

print max(max_utility[-1])
