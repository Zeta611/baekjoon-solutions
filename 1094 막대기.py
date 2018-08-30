pol;len_init = 64
part = [len_init]
len_fin = input()
while sum(part) > len_fin:
    shortest = part.pop()
    s = sum(part) + shortest / 2
    if s >= len_fin:
        part.append(shortest / 2)
    else:
        part.extend([shortest / 2] * 2)
print len(part)
