"""Project Euler Problem 69: Totient Maximum"""


def solve(limit: int = 1_000_000) -> int:
    n = 1
    for prime in [2, 3, 5, 7, 11, 13, 17, 19, 23]:
        if n * prime > limit:
            return n
        n *= prime
    return n


if __name__ == "__main__":
    print(solve())
