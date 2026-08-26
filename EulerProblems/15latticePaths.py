"""Project Euler Problem 15: Lattice Paths"""

import math


def solve(rows: int = 20, cols: int = 20) -> int:
    n = rows + cols
    return math.comb(n, rows)


if __name__ == "__main__":
    print(solve())
