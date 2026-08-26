"""Project Euler Problem 44: Pentagon Numbers"""


def pentagonal(n: int) -> int:
    return n * (3 * n - 1) // 2


def is_pentagonal(value: int) -> bool:
    root = int((1 + (1 + 24 * value) ** 0.5) / 6)
    return pentagonal(root) == value


def solve() -> int:
    pentagonals = []
    n = 1

    while True:
        current = pentagonal(n)
        for previous in pentagonals:
            diff = current - previous
            if is_pentagonal(diff):
                return diff
        pentagonals.append(current)
        n += 1


if __name__ == "__main__":
    print(solve())
