s = []
m = input()
t = range(m, 0, -1)
p = ""
flag = 1
for _ in range(m):
    n = input()
    while len(s) == 0 or s[-1] < n:
        s.append(t.pop())
        p += '+\n'
    if s[-1] == n:
        s.pop()
        p += '-\n'
if len(s) or len(t):
    print "NO"
else:
    print p
