# ACM-ICPC > Regionals > Asia > Korea > Nationwide Internet Competition > Asia Regional - Daejeon Nationalwide Internet Competition 2014 A
for _ in range(input()):
    h, w, n = map(int, raw_input().split())
    floor = n % h
    if floor == 0:
        floor = h
    num = n / h
    if n % h:
        num += 1
    print floor * 100 + num
