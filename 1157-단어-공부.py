s = raw_input().upper()
occ = dict()
for e in s:
    if e not in occ:
        occ[e] = 1
    else:
        occ[e] += 1
m = 0
argm = None
for key in occ:
    if occ[key] > m:
        m = occ[key]
        argm = key
    elif occ[key] == m:
        argm = '?'

print argm
