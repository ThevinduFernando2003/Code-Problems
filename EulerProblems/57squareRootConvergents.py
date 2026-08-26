"""Project Euler Problem 57: Square Root Convergents"""


def solve(limit: int = 1000) -> int:
    numerator, denominator = 3, 2
    count = 0

    for _ in range(2, limit + 1):
        numerator, denominator = numerator + 2 * denominator, numerator + denominator
        if len(str(numerator)) > len(str(denominator)):
            count += 1

    return count


if __name__ == "__main__":
    print(solve())
