"""Project Euler Problem 14: Longest Collatz Sequence"""

from functools import lru_cache


@lru_cache(maxsize=None)
def chain_length(n: int) -> int:
    if n == 1:
        return 1
    if n % 2 == 0:
        return 1 + chain_length(n // 2)
    return 1 + chain_length(3 * n + 1)


def solve(limit: int = 1_000_000) -> int:
    best_start = 1
    best_length = 1

    for start in range(2, limit):
        length = chain_length(start)
        if length > best_length:
            best_length = length
            best_start = start

    return best_start


if __name__ == "__main__":
    print(solve())
