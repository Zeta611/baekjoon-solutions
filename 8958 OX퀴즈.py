# ACM-ICPC > Regionals > Asia > Korea > Asia Regional - Seoul 2005 A
import sys

t = sys.stdin.readlines()[1:]
for l in t:
    s = c = int(l[0] == "O")
    for i in range(1, len(l)):
        x = l[i] == "O"
        if x:
            c *= (l[i - 1] == "O")
        c += 1 * x
        s += c * x
    print s
