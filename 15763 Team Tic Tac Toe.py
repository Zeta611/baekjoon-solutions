# Olympiad > USA Computing Olympiad > 2017-2018 Season > USACO 2018 US Open Contest > Bronze 1
table = map(list, [raw_input() for _ in range(3)])


def add_individual(s, line):
    if len(set(line)) == 1:
        s.add(line[0])


def add_team(s, line):
    if len(set(line)) == 2:
        s.add(tuple(sorted(list(set(line)))))


individual = set([])
team = set([])

for row in table:
    add_individual(individual, row)
    add_team(team, row)

for j in range(3):
    vert = [table[0][j], table[1][j], table[2][j]]
    add_individual(individual, vert)
    add_team(team, vert)

diag1 = [table[0][0], table[1][1], table[2][2]]
diag2 = [table[0][2], table[1][1], table[2][0]]
add_individual(individual, diag1)
add_individual(individual, diag2)
add_team(team, diag1)
add_team(team, diag2)

print len(individual)
print len(team)
