"""Project Euler Problem 33: Digit Cancelling Fractions"""

from fractions import Fraction


def solve() -> int:
    product = Fraction(1, 1)

    for a in range(1, 10):
        for b in range(1, 10):
            for c in range(1, 10):
                for d in range(1, 10):
                    numerator = 10 * a + b
                    denominator = 10 * c + d

                    if numerator >= denominator:
                        continue

                    if b == c and a != d and numerator * d == denominator * a:
                        product *= Fraction(denominator, numerator)

                    if a == d and b != c and numerator * c == denominator * b:
                        product *= Fraction(denominator, numerator)

    return product.numerator // product.denominator


if __name__ == "__main__":
    print(solve())
