"""Project Euler Problem 69: Totient Maximum"""


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


def solve(limit: int = 1_000_000) -> int:
    best_n = 1
    best_ratio = 0

    for n in range(2, limit + 1):
        ratio = n / phi(n)
        if ratio > best_ratio:
            best_ratio = ratio
            best_n = n

    return best_n


if __name__ == "__main__":
    print(solve())
