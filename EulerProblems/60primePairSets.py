"""Project Euler Problem 60: Prime Pair Sets"""

import itertools


def sieve(limit: int) -> list[int]:
    is_prime = [True] * limit
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(limit**0.5) + 1):
        if is_prime[i]:
            is_prime[i * i : limit : i] = [False] * len(is_prime[i * i : limit : i])
    return [i for i, prime in enumerate(is_prime) if prime]


def solve() -> int:
    primes = sieve(10_000)
    prime_set = set(primes)
    valid = []

    for left, right in itertools.combinations(primes, 2):
        if left > 9_999:
            break
        if int(f"{left}{right}") in prime_set and int(f"{right}{left}") in prime_set:
            valid.append(left)
            valid.append(right)

    candidates = sorted(set(valid))
    best = None

    for combo in itertools.combinations(candidates, 5):
        ok = True
        for a, b in itertools.combinations(combo, 2):
            if int(f"{a}{b}") not in prime_set or int(f"{b}{a}") not in prime_set:
                ok = False
                break
        if ok:
            total = sum(combo)
            if best is None or total < best:
                best = total

    return best


if __name__ == "__main__":
    print(solve())
