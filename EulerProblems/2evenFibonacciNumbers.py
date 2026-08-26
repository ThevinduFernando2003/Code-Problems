"""Project Euler Problem 2: Even Fibonacci Numbers"""


def solve(limit: int = 4_000_000) -> int:
    a, b = 1, 2
    total = 0

    while a <= limit:
        if a % 2 == 0:
            total += a
        a, b = b, a + b

    return total


if __name__ == "__main__":
    print(solve())
