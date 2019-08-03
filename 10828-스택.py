stack = []
for _ in range(input()):
    command = raw_input()
    if "push" in command:
        stack.append(int(command.split()[1]))
    elif command == "pop":
        if len(stack):
            print stack.pop()
        else:
            print -1
    elif command == "size":
        print len(stack)
    elif command == "empty":
        print (len(stack) == 0) * 1
    elif command == "top":
        if len(stack):
            print stack[-1]
        else:
            print -1
