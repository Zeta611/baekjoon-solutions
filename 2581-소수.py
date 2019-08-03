# -*- coding:utf-8 -*-
# Olympiad > 한국정보올림피아드시․도지역본선 > 지역본선 2006 > 중등부 1


def p(n):
    for m in xrange(2, int(n ** .5) + 1):
        if n % m == 0:
            return 0
    return 1 and n > 1


s = m = -1
for n in xrange(input(), input() + 1):
    if s == -1:
        m = n
    s += n * p(n)
if s == -1:
    print s
else:
    print s + 1
if s + 1:
    print m
