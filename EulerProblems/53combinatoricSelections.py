"""Project Euler Problem 53: Combinatoric Selections"""

from math import comb


def solve(limit: int = 1_000_000, n_max: int = 100) -> int:
    return sum(1 for n in range(1, n_max + 1) for r in range(n + 1) if comb(n, r) > limit)


if __name__ == "__main__":
    print(solve())
