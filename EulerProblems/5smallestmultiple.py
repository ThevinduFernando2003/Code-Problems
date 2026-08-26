"""Project Euler Problem 5: Smallest Multiple"""


import math


def solve(n: int = 20) -> int:
    return math.lcm(*range(1, n + 1))


if __name__ == "__main__":
    print(solve())
