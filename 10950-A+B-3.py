from functools import reduce

number_of_cases = int(input())
for _ in range(number_of_cases):
    print(reduce(lambda x, y: x + y, map(int, input().split())))
