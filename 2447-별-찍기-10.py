import math

memo = [["*"]]


def star(n):
    if n == 0:
        return memo[0]
    star_tower = []
    if len(memo) > n:
        return memo[n]
    prev_star = star(n - 1)

    for row in prev_star:
        star_tower.append(row * 3)

    for row in prev_star:
        star_tower.append(row + " " * len(row) + row)

    for row in prev_star:
        star_tower.append(row * 3)

    memo.append(star_tower)
    return star_tower


n = int(round(math.log(int(input()), 3)))
to_p = star(n)
for line in to_p:
    print(line)
