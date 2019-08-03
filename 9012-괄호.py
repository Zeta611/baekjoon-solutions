# ACM-ICPC > Regionals > Asia > Korea > Nationwide Internet Competition > Asia Regional - Daejeon Nationalwide Internet Competition 2012 G
for _ in range(input()):
    c = f = 0
    for e in raw_input():
        if e == '(':
            c += 1
        else:
            c -= 1
        if c < 0:
            f = 1
    if c or f:
        print "NO"
    else:
        print "YES"
