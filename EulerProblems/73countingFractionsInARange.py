"""Project Euler Problem 73: Counting Fractions in a Range"""

from math import gcd


def solve(limit: int = 12_000) -> int:
    count = 0
    left = 1 / 3
    right = 1 / 2

    for denominator in range(2, limit + 1):
        start = denominator // 3 + 1
        end = (denominator - 1) // 2
        for numerator in range(start, end + 1):
            if gcd(numerator, denominator) == 1:
                value = numerator / denominator
                if left < value < right:
                    count += 1

    return count


if __name__ == "__main__":
    print(solve())
