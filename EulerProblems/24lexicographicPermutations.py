"""Project Euler Problem 24: Lexicographic Permutations"""

import math


def solve(n: int = 1_000_000) -> int:
    digits = list(range(10))
    result = []
    index = n - 1

    for place in range(9, 0, -1):
        factorial = math.factorial(place)
        digit_index = index // factorial
        result.append(digits.pop(digit_index))
        index %= factorial

    result.append(digits[0])
    return int("".join(map(str, result)))


if __name__ == "__main__":
    print(solve())
