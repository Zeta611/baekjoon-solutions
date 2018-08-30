# Contest > Croatian Open Competition in Informatics > COCI 2009/2010 > Contest #1 1
a = map(str, range(1, 9))
b = raw_input().split()
print["ascending", "descending", "mixed"][[a == b, a == b[::-1], 1].index(1)]
