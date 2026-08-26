"""Project Euler Problem 10: Summation of Primes"""


def solve(limit: int = 2_000_000) -> int:
    sieve = [True] * limit
    sieve[0] = sieve[1] = False

    for i in range(2, int(limit ** 0.5) + 1):
        if sieve[i]:
            sieve[i * i : limit : i] = [False] * len(sieve[i * i : limit : i])

    return sum(i for i, is_prime in enumerate(sieve) if is_prime)


if __name__ == "__main__":
    print(solve())
