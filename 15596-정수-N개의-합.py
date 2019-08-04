from functools import reduce


def solve(a: list) -> int:
    return reduce(lambda x, y: x + y, a)
