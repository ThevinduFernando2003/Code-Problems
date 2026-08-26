"""Project Euler Problem 71: Ordered Fractions"""

import itertools


def solve(den_limit: int = 1_000_000) -> int:
    left = 3 / 7
    best = (0, 1)

    for denominator in range(2, den_limit + 1):
        numerator = (3 * denominator) // 7
        while numerator / denominator >= left:
            numerator -= 1
        if numerator > 0 and numerator / denominator > best[0] / best[1]:
            best = (numerator, denominator)

    return best[0]


if __name__ == "__main__":
    print(solve())
