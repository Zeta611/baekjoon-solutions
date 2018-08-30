# ACM-ICPC > Regionals > Europe > Northwestern European Regional Contest > Benelux Algorithm Programming Contest > BAPC 2012 I

from collections import deque

for _ in range(input()):
    p = deque(raw_input())
    n = input()
    x = deque(input())
    reverse = 0
    error = False
    while p:
        op = p.popleft()
        if op == 'R':
            reverse += 1
        else:
            if x:
                if reverse % 2:
                    x.pop()
                else:
                    x.popleft()
            else:
                error = True
                break
    if not error:
        if reverse % 2:
            x.reverse()
        print str(list(x)).replace(' ', '')
    else:
        print "error"
