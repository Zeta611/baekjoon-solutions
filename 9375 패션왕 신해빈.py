# ACM-ICPC > Regionals > Europe > Northwestern European Regional Contest > Benelux Algorithm Programming Contest > BAPC 2013 I
for _ in range(input()):
    attributes = dict()
    for _ in range(input()):
        name, category = raw_input().split()
        if category in attributes:
            attributes[category].add(name)
        else:
            attributes[category] = {name}
    cnt = 1
    for category in attributes:
        cnt *= len(attributes[category]) + 1
    print cnt - 1
