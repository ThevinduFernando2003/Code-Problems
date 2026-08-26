"""Project Euler Problem 77: Prime Summations"""


def solve(target: int = 5000) -> int:
    ways = [0] * (target + 1)
    ways[0] = 1
    primes = []

    for candidate in range(2, target + 1):
        is_prime = all(candidate % p for p in primes)
        if is_prime:
            primes.append(candidate)
            for amount in range(candidate, target + 1):
                ways[amount] += ways[amount - candidate]

        if ways[target] > 5000:
            return candidate

    return target


if __name__ == "__main__":
    print(solve())
