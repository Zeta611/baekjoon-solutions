n = input()
wine = [0] * n
for i in xrange(n):
    wine[i] = input()
if n > 1:
    dp_1 = [wine[0], wine[1]] + [0] * (n - 2)
    dp_2 = [wine[0], wine[0] + wine[1]] + [0] * (n - 2)
else:
    dp_1 = dp_2 = [wine[0]]

for i in xrange(2, n):
    if i > 3:
        dp_1[i] = max(dp_1[i - 2], dp_2[i - 2], dp_2[i - 3]) + wine[i]
    else:
        dp_1[i] = max(dp_1[i - 2], dp_2[i - 2]) + wine[i]
    dp_2[i] = dp_1[i - 1] + wine[i]
print max(dp_1[n - 1], dp_1[n - 2], dp_2[n - 1], dp_2[n - 2])
