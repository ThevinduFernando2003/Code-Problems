"""Project Euler Problem 100: Arranged Probability"""


def solve(limit: int = 10**12) -> int:
    # Solutions to 2b(b-1) = n(n-1) come from the Pell recurrence.
    blue, total = 15, 21
    while total <= limit:
        blue, total = 3 * blue + 2 * total - 2, 4 * blue + 3 * total - 3
    return blue


if __name__ == "__main__":
    print(solve())
