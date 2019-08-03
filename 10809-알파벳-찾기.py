w = raw_input()
a = dict()
for i in range(len(w)):
    l = w[i]
    if l not in a:
        a[l] = i
for l in map(chr, range(97, 123)):
    if l in a:
        print a[l],
    else:
        print -1,
