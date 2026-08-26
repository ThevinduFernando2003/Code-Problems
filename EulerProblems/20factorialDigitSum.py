"""Project Euler Problem 20: Factorial Digit Sum"""

import math


def solve(n: int = 100) -> int:
    return sum(int(digit) for digit in str(math.factorial(n)))


if __name__ == "__main__":
    print(solve())
