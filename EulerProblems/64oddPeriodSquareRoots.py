"""Project Euler Problem 64: Odd Period Square Roots"""


def period(n: int) -> int:
    m = 0
    d = 1
    a0 = int(n**0.5)
    a = a0
    seen = {}
    count = 0

    while True:
        m = d * a - m
        d = (n - m * m) // d
        a = (a0 + m) // d
        state = (m, d, a)
        if state in seen:
            return count
        seen[state] = count
        count += 1


def solve(limit: int = 10_000) -> int:
    return sum(period(n) % 2 == 1 for n in range(2, limit + 1) if int(n**0.5) ** 2 != n)


if __name__ == "__main__":
    print(solve())
