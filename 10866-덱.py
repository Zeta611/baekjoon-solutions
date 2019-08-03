from collections import deque

d = deque()
for _ in range(input()):
    command = raw_input().split()
    if command[0] == "push_front":
        d.appendleft(command[1])
    elif command[0] == "push_back":
        d.append(command[1])
    elif command[0] == "pop_front":
        if d:
            print d.popleft()
        else:
            print -1
    elif command[0] == "pop_back":
        if d:
            print d.pop()
        else:
            print -1
    elif command[0] == "size":
        print len(d)
    elif command[0] == "empty":
        print (len(d) == 0) * 1
    elif command[0] == "front":
        if d:
            print d[0]
        else:
            print -1
    else:
        if d:
            print d[-1]
        else:
            print -1
