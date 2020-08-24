n = int(input())
utility = [0] * n
for i in range(n):
    utility[i] = int(input())

if n == 1:
    print(utility[0])
else:
    max_utility_double = utility[:]  # Last move: double stair step
    max_utility_single = utility[:]  # Last move: single stair step
    max_utility_single[1] += utility[0]

    for i in range(2, n):
        max_utility_double[i] += max_utility_single[i - 2]
        max_utility_single[i] += max(
            max_utility_double[i - 1],
            max_utility_single[i - 2]
        )

    print(max_utility_single[-1])
