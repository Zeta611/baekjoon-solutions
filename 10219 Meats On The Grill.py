# Contest > Coder's High > Coder's High 2014 F
# Contest > Coder's High > Coder's high 2016 Round 2: Nexon Arena PB
for _ in xrange(input()):
    H, W = map(int, raw_input().split())
    grill = []
    for _ in xrange(H):
        grill.append(raw_input())
    for line in grill:
        print line[::-1]
