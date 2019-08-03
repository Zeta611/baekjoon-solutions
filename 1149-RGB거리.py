n = input()
cost_r = [0] * n
cost_g = [0] * n
cost_b = [0] * n

for i in xrange(n):
    r, g, b = map(int, raw_input().split())
    cost_r[i] = r
    cost_g[i] = g
    cost_b[i] = b

min_cost_r = [cost_r[0]] + [0] * (n - 1)
min_cost_g = [cost_g[0]] + [0] * (n - 1)
min_cost_b = [cost_b[0]] + [0] * (n - 1)

for i in xrange(1, n):
    min_cost_r[i] = min(min_cost_g[i - 1], min_cost_b[i - 1]) + cost_r[i]
    min_cost_g[i] = min(min_cost_r[i - 1], min_cost_b[i - 1]) + cost_g[i]
    min_cost_b[i] = min(min_cost_r[i - 1], min_cost_g[i - 1]) + cost_b[i]

print min(min_cost_r[-1], min_cost_g[-1], min_cost_b[-1])
