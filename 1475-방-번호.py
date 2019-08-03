c = [0] * 10
for d in raw_input():
    c[int(d)] -= 1
c[6] = (c[6] + c[9]) / 2
print -min(c[:9])
