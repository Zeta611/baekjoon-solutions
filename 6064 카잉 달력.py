# ACM-ICPC > Regionals > Asia > Korea > Nationwide Internet Competition > Asia Regional - Daejeon Nationalwide Internet Competition 2013 B
for _ in range(input()):
    m, n, x, y = map(int, raw_input().split())
    found = False
    for yr in xrange(x, m * n + 1, m):
        x_try = yr % m
        y_try = yr % n
        if x_try == 0:
            x_try = m
        if y_try == 0:
            y_try = n
        if (x_try, y_try) == (x, y):
            print yr
            found = True
            break
    if not found:
        print -1
