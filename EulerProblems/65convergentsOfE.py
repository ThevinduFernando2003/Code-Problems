"""Project Euler Problem 65: Convergents of e"""

from fractions import Fraction


def solve(terms: int = 100) -> int:
    convergent = Fraction(2, 1)
    numerator, denominator = 1, 2

    for k in range(2, terms + 1):
        multiplier = 1 if k % 3 else 2
        convergent = convergent + Fraction(1, denominator)
        numerator, denominator = denominator, denominator * multiplier + numerator

    return sum(int(digit) for digit in str(convergent.numerator))


if __name__ == "__main__":
    print(solve())
