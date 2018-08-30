# Contest > Waterloo's local Programming Contests > 28 September, 2002 D
for i in range(input()):
    l = map(float, raw_input().split())
    m = l.pop(0)
    print "%.3f%%" % (sum(map(lambda x: sum(l) / m < x, l)) * 100 / m)
