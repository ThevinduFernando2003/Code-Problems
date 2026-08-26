"""Project Euler Problem 28: Number Spiral Diagonals"""


def solve(size: int = 1001) -> int:
    total = 1
    value = 1

    for layer in range(1, size // 2 + 1):
        step = 2 * layer
        corners = [value + step * i for i in range(1, 5)]
        total += sum(corners)
        value = corners[-1]

    return total


if __name__ == "__main__":
    print(solve())
