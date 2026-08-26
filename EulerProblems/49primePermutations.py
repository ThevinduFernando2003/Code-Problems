"""Project Euler Problem 49: Prime Permutations"""

from itertools import permutations


def is_prime(n: int) -> bool:
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True


def solve() -> int:
    for base in range(1000, 10000):
        if not is_prime(base):
            continue

        digits = sorted(str(base))
        perm_values = {int("".join(p)) for p in set(permutations(digits))}
        primes = sorted(value for value in perm_values if 1000 <= value <= 9999 and is_prime(value))

        if len(primes) < 3:
            continue

        for i in range(len(primes)):
            for j in range(i + 1, len(primes)):
                for k in range(j + 1, len(primes)):
                    a, b, c = primes[i], primes[j], primes[k]
                    if c - b == b - a:
                        return int(f"{a}{b}{c}")

    return 0


if __name__ == "__main__":
    print(solve())
