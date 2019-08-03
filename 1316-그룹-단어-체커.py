cnt = 0
for _ in range(input()):
    word = raw_input()
    group_word = True
    record = {word[0]}
    m = len(word)
    for i in xrange(m - 1):
        current = word[i + 1]
        if current != word[i]:
            if current not in record:
                record.add(current)
            else:
                group_word = False
                break
    if group_word:
        cnt += 1
print cnt
