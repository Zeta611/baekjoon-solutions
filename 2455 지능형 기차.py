# -*- coding: utf-8 -*-
# Olympiad > 한국정보올림피아드시․도지역본선 > 지역본선 2011 > 초등부 1
num = 0
m = 0
for _ in xrange(4):
    a, b = map(int, raw_input().split())
    num -= a
    num += b
    if num > m:
        m = num
print m