# Contest > Croatian Open Competition in Informatics > COCI 2009/2010 > Contest #3 1

n, m = map(int, raw_input()[::-1].split())
print n * (n > m) + m * (m > n)
