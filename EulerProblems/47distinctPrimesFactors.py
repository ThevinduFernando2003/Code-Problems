"""Project Euler Problem 47: Distinct Primes Factors"""


def prime_factors(n: int) -> set[int]:
    factors = set()
    while n % 2 == 0:
        factors.add(2)
        n //= 2

    factor = 3
    while factor * factor <= n:
        while n % factor == 0:
            factors.add(factor)
            n //= factor
        factor += 2

    if n > 1:
        factors.add(n)

    return factors


def solve(consecutive: int = 4) -> int:
    number = 2
    while True:
        if all(len(prime_factors(number + offset)) == consecutive for offset in range(consecutive)):
            return number
        number += 1


if __name__ == "__main__":
    print(solve())
