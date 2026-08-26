"""Project Euler Problem 80: Square Root Digital Expansion"""

from decimal import Decimal, getcontext


def digit_sum(n: int, places: int = 100) -> int:
    getcontext().prec = places + 10
    value = Decimal(n).sqrt()
    digits = str(value).replace(".", "")[:places]
    return sum(int(d) for d in digits)


def solve(limit: int = 100) -> int:
    total = 0
    for n in range(1, limit + 1):
        if int(n**0.5) ** 2 == n:
            continue
        total += digit_sum(n)
    return total


if __name__ == "__main__":
    print(solve())
