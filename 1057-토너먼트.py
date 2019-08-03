N, a, b = map(int, raw_input().split())
if a > b:
    a, b = b, a
round = 1
found = False
while 2 * N > 2 ** round:
    group_a = group_b = 0
    while a > group_a * 2 ** round:
        group_a += 1
    while b > group_b * 2 ** round:
        group_b += 1
    if group_a == group_b:
        print round
        found = True
        break
    round += 1
if not found:
    print -1
