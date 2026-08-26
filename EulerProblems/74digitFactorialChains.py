"""Project Euler Problem 74: Digit Factorial Chains"""

import math


def digit_factorial(n: int) -> int:
    return sum(math.factorial(int(d)) for d in str(n))


def chain_length(start: int, cache: dict[int, int]) -> int:
    seen = {}
    current = start
    length = 0

    while current not in seen and current not in cache:
        seen[current] = length
        current = digit_factorial(current)
        length += 1

    if current in cache:
        total = length + cache[current]
    else:
        total = length + seen[current]

    for value, index in seen.items():
        cache[value] = total - index

    return total


def solve(limit: int = 1_000_000, target: int = 60) -> int:
    cache = {169: 3, 871: 2, 872: 2, 1454: 3, 45362: 4}
    return sum(1 for n in range(1, limit) if chain_length(n, cache) == target)


if __name__ == "__main__":
    print(solve())
