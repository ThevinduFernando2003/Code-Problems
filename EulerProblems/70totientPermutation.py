"""Project Euler Problem 70: Totient Permutation"""

import itertools


def phi(n: int) -> int:
    result = n
    value = n
    p = 2
    while p * p <= value:
        if value % p == 0:
            while value % p == 0:
                value //= p
            result -= result // p
        p += 1
    if value > 1:
        result -= result // value
    return result


def solve(limit: int = 10_000_000) -> int:
    best = (1, 1)

    for n in range(2, limit + 1):
        value = phi(n)
        if sorted(str(n)) == sorted(str(value)):
            ratio = n / value
            if ratio < best[0] / best[1]:
                best = (n, value)

    return best[0]


if __name__ == "__main__":
    print(solve())
