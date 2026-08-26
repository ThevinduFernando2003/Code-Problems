"""Project Euler Problem 51: Prime Digit Replacements"""

from itertools import combinations


def sieve(limit: int) -> list[int]:
    is_prime = [True] * limit
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(limit**0.5) + 1):
        if is_prime[i]:
            is_prime[i * i : limit : i] = [False] * len(is_prime[i * i : limit : i])
    return [i for i, prime in enumerate(is_prime) if prime]


def solve(family_size: int = 8) -> int:
    primes = sieve(1_000_000)
    prime_set = set(primes)

    for prime in primes:
        digits = str(prime)
        n = len(digits)
        for width in range(1, n):
            for positions in combinations(range(n), width):
                if len({digits[i] for i in positions}) != 1:
                    continue

                family = []
                for digit in "0123456789":
                    if 0 in positions and digit == "0":
                        continue
                    candidate = list(digits)
                    for pos in positions:
                        candidate[pos] = digit
                    value = int("".join(candidate))
                    if value in prime_set and len(str(value)) == n:
                        family.append(value)

                if len(family) >= family_size:
                    return min(family)

    return 0


if __name__ == "__main__":
    print(solve())
