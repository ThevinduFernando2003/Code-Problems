"""Project Euler Problem 87: Prime Power Triples"""


def sieve(limit: int) -> list[int]:
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(limit**0.5) + 1):
        if is_prime[i]:
            is_prime[i * i : limit + 1 : i] = [False] * len(is_prime[i * i : limit + 1 : i])
    return [i for i, prime in enumerate(is_prime) if prime]


def solve(limit: int = 50_000_000) -> int:
    primes = sieve(int(limit ** (1 / 2)) + 1)
    values = set()

    for a in primes:
        fourth = a**4
        if fourth >= limit:
            break
        for b in primes:
            cube = b**3
            if fourth + cube >= limit:
                break
            for c in primes:
                total = fourth + cube + c * c
                if total >= limit:
                    break
                values.add(total)

    return len(values)


if __name__ == "__main__":
    print(solve())
