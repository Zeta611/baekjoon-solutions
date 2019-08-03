x = int(raw_input().split()[1])
for e in map(int, raw_input().split()):
    if e < x:
        print e,
