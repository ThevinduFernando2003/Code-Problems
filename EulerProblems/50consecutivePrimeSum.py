"""Project Euler Problem 50: Consecutive Prime Sum"""


def sieve(limit: int) -> list[int]:
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False

    for i in range(2, int(limit**0.5) + 1):
        if is_prime[i]:
            is_prime[i * i : limit + 1 : i] = [False] * len(is_prime[i * i : limit + 1 : i])

    return [i for i, prime in enumerate(is_prime) if prime]


def solve(limit: int = 1_000_000) -> int:
    primes = sieve(limit)
    prefix = [0]
    for prime in primes:
        prefix.append(prefix[-1] + prime)

    best_prime = 0
    best_length = 0

    for start in range(len(primes)):
        for end in range(start + best_length, len(prefix) - 1):
            total = prefix[end + 1] - prefix[start]
            if total >= limit:
                break
            length = end - start + 1
            if length > best_length and total in primes:
                best_length = length
                best_prime = total

    return best_prime


if __name__ == "__main__":
    print(solve())
