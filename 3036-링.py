# Contest > Croatian Open Competition in Informatics > COCI 2006/2007 > Contest #4 3
def ratio(a, b):
    if a > b:
        m, n = a, b
    else:
        m, n = b, a
    while n:
        m, n = n, m % n
    return str(a / m) + '/' + str(b / m)


N = input()
ring = map(int, raw_input().split())
for r in ring[1:]:
    print ratio(ring[0], r)
