# -*- coding:utf-8 -*-
# Olympiad > 한국정보올림피아드시․도지역본선 > 지역본선 2006 > 초등부 4
n = input()
utility = [0] * n
for i in xrange(n):
    utility[i] = input()

max_utility_double = utility[:]  # Last move: double stair step
max_utility_single = utility[:]  # Last move: single stair step

max_utility_single[1] += utility[0]

for i in xrange(2, n):
    max_utility_double[i] += max_utility_single[i - 2]
    max_utility_single[i] += max(max_utility_double[i - 1], max_utility_single[i - 2])

print max_utility_single[-1]

# def max_utility(n, double_step):
#     if n == 1:
#         return utility[0]
#     if n == 2:
#         if double_step:
#             return utility[1]
#         return utility[1] + utility[0]
#     if double_step:
#         return max_utility(n - 2, False) + utility[n - 1]
#     return max(max_utility(n - 1, True), max_utility(n - 2, False)) + utility[n - 1]
#
#
# print max_utility(n, False)
