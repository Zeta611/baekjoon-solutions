# ACM-ACM-ICPC > Regionals > North America > Greater New York Region > 2011 Greater New York Programming Contest A

for _ in range(input()):
    n, s = raw_input().split()
    repeat = ""
    for e in s:
        for _ in range(int(n)):
            repeat += e
    print repeat
