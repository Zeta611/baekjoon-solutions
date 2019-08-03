# Contest > Croatian Open Competition in Informatics > COCI 2008/2009 > Contest #5 1

w = raw_input()
v = len(w)
for i in range(v):
    if w[i] in ['=', '-']:
        if i > 1 and w[i - 2:i] == "dz":
            v -= 2
        else:
            v -= 1
    if w[i] == 'j':
        if i > 0 and w[i - 1] in ['l', 'n']:
            v -= 1
print v
