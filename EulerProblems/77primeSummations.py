"""Project Euler Problem 77: Prime Summations"""


def sieve(limit: int) -> list[int]:
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(limit**0.5) + 1):
        if is_prime[i]:
            is_prime[i * i : limit + 1 : i] = [False] * len(is_prime[i * i : limit + 1 : i])
    return [i for i, prime in enumerate(is_prime) if prime]


def solve(target_ways: int = 5000) -> int:
    limit = 100
    while True:
        primes = sieve(limit)
        ways = [0] * (limit + 1)
        ways[0] = 1
        for prime in primes:
            for amount in range(prime, limit + 1):
                ways[amount] += ways[amount - prime]

        for n in range(2, limit + 1):
            if ways[n] > target_ways:
                return n
        limit *= 2


if __name__ == "__main__":
    print(solve())
