"""Project Euler Problem 64: Odd Period Square Roots"""


def period_length(n: int) -> int:
    a0 = int(n**0.5)
    if a0 * a0 == n:
        return 0

    period = 0
    m, d, a = 0, 1, a0
    while a != 2 * a0:
        m = d * a - m
        d = (n - m * m) // d
        a = (a0 + m) // d
        period += 1
    return period


def solve(limit: int = 10_000) -> int:
    return sum(1 for n in range(2, limit + 1) if period_length(n) % 2 == 1)


if __name__ == "__main__":
    print(solve())
