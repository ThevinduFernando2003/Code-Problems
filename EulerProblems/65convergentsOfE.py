"""Project Euler Problem 65: Convergents of e"""

from fractions import Fraction


def e_terms(count: int) -> list[int]:
    terms = []
    for k in range(count):
        if k == 0:
            terms.append(2)
        elif k % 3 == 2:
            terms.append(2 * (k // 3 + 1))
        else:
            terms.append(1)
    return terms


def solve(n: int = 100) -> int:
    terms = e_terms(n)
    convergent = Fraction(terms[-1], 1)
    for term in reversed(terms[:-1]):
        convergent = term + 1 / convergent
    return sum(int(digit) for digit in str(convergent.numerator))


if __name__ == "__main__":
    print(solve())
