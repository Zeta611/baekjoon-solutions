# -*- coding:utf-8 -*-
# Olympiad > 한국정보올림피아드시․도지역본선 > 지역본선 2008 > 초등부 4, 중등부 2
s, v, c = [], 1, 0
for e in raw_input():
    if e in ['[', '(']:
        s.append(e)
    elif e == ')':
        if len(s) == 0:
            v = 0
            break
        a = s.pop()
        if a == '(':
            s.append(2)
        elif a == '[':
            v = 0
            break
        else:
            while len(s) and type(s[-1]) == int:
                a += s.pop()
            if len(s) and s.pop() == '(':
                s.append(a * 2)
            else:
                v = 0
                break
    else:
        if len(s) == 0:
            v = 0
            break
        a = s.pop()
        if a == '[':
            s.append(3)
        elif a == '(':
            v = 0
            break
        else:
            while len(s) and type(s[-1]) == int:
                a += s.pop()
            if len(s) and s.pop() == '[':
                s.append(a * 3)
            else:
                v = 0
                break
for e in s:
    if type(e) == int:
        c += e
    else:
        v = 0
print c * v
