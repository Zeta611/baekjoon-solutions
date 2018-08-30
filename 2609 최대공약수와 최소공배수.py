# -*- coding: utf-8 -*-
# Olympiad > 한국정보올림피아드시․도지역본선 > 지역본선 2004 > 중등부 1, 고등부 1
def gcd_lcm(a, b):
    m = a * b
    if a < b:
        a, b = b, a
    while b:
        a, b = b, a % b
    return str(a) + '\n' + str(m / a)


print reduce(gcd_lcm, map(int, raw_input().split()))
