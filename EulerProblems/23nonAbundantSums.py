"""Project Euler Problem 23: Non-Abundant Sums"""


def proper_divisor_sum(n: int) -> int:
    total = 1
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            total += i
            if i * i != n:
                total += n // i
    return total


def solve(limit: int = 28_123) -> int:
    abundants = [n for n in range(12, limit + 1) if proper_divisor_sum(n) > n]
    cannot_be_written = [False] * (limit + 1)

    for i, a in enumerate(abundants):
        for b in abundants[i:]:
            total = a + b
            if total > limit:
                break
            cannot_be_written[total] = True

    return sum(n for n in range(1, limit + 1) if not cannot_be_written[n])


if __name__ == "__main__":
    print(solve())
