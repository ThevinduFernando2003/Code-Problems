"""Project Euler Problem 45: Triangular, Pentagonal, and Hexagonal"""


def hexagonal(n: int) -> int:
    return n * (2 * n - 1)


def is_triangular(value: int) -> bool:
    root = int((8 * value + 1) ** 0.5)
    return root * root == 8 * value + 1


def is_pentagonal(value: int) -> bool:
    root = int((1 + (1 + 24 * value) ** 0.5) / 6)
    return root * (3 * root - 1) // 2 == value


def solve() -> int:
    n = 285
    while True:
        value = hexagonal(n)
        if is_triangular(value) and is_pentagonal(value):
            return value
        n += 1


if __name__ == "__main__":
    print(solve())
