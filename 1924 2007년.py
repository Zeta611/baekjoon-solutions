a, b = 30, 31
d = {1: b, 2: 28, 3: b, 4: a, 5: b, 6: a, 7: b, 8: b, 9: a, 10: b, 11: a, 12: b}
M, D = map(int, raw_input().split())
print["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"][(sum([d[m] for m in range(1, M)]) + D) % 7]
