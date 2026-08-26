"""Project Euler Problem 61: Cyclical Figurate Numbers"""

import itertools


def triangle(n: int) -> int:
    return n * (n + 1) // 2


def square(n: int) -> int:
    return n * n


def pentagonal(n: int) -> int:
    return n * (3 * n - 1) // 2


def hexagonal(n: int) -> int:
    return n * (2 * n - 1)


def heptagonal(n: int) -> int:
    return n * (5 * n - 3) // 2


def octagonal(n: int) -> int:
    return n * (3 * n - 2)


def generate(kind, limit=1_000_000):
    values = []
    n = 1
    while True:
        value = kind(n)
        if value >= limit:
            break
        if value >= 1000:
            values.append(value)
        n += 1
    return values


def solve() -> int:
    kinds = [triangle, square, pentagonal, hexagonal, heptagonal, octagonal]
    numbers = {i: set(generate(fn)) for i, fn in enumerate(kinds)}

    for perm in itertools.permutations(range(6)):
        for n1 in numbers[perm[0]]:
            suffix = n1 % 100
            for n2 in numbers[perm[1]]:
                if n2 % 100 != suffix or n2 // 100 != n1 % 100:
                    continue
                suffix2 = n2 % 100
                for n3 in numbers[perm[2]]:
                    if n3 % 100 != suffix2 or n3 // 100 != n2 % 100:
                        continue
                    suffix3 = n3 % 100
                    for n4 in numbers[perm[3]]:
                        if n4 % 100 != suffix3 or n4 // 100 != n3 % 100:
                            continue
                        suffix4 = n4 % 100
                        for n5 in numbers[perm[4]]:
                            if n5 % 100 != suffix4 or n5 // 100 != n4 % 100:
                                continue
                            suffix5 = n5 % 100
                            for n6 in numbers[perm[5]]:
                                if n6 % 100 != suffix5 or n6 // 100 != n5 % 100:
                                    continue
                                if n6 // 100 == n1 % 100:
                                    return n1 + n2 + n3 + n4 + n5 + n6
    return 0


if __name__ == "__main__":
    print(solve())
