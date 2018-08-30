from collections import deque

q = deque()
for _ in range(input()):
    cmd = raw_input()
    if cmd == "front":
        if len(q):
            print q[0]
        else:
            print -1
    elif cmd == "back":
        if len(q):
            print q[-1]
        else:
            print -1
    elif cmd == "empty":
        print (len(q) == 0) * 1
    elif cmd == "size":
        print len(q)
    elif cmd == "pop":
        if len(q):
            print q.popleft()
        else:
            print -1
    else:
        q.append(int(cmd.split()[1]))
