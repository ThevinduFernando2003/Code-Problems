"""Project Euler Problem 94: Almost Equilateral Triangles"""

from math import isqrt


def has_integer_area(side: int, base: int) -> bool:
    squared = 4 * side * side * side * side - (2 * side * side - base * base) ** 2
    if squared <= 0:
        return False
    root = isqrt(squared)
    return root * root == squared


def solve(limit: int = 1_000_000_000) -> int:
    total = 0
    x, y = 2, 1

    while True:
        candidates = (2 * (x - 1), 2 * (x + 1))
        if min(candidates) > limit:
            return total

        for perimeter in candidates:
            if perimeter > limit or perimeter <= 0:
                continue
            for delta in (1, -1):
                if (perimeter - delta) % 3:
                    continue
                equal_side = (perimeter - delta) // 3
                if equal_side > 1 and has_integer_area(equal_side, equal_side + delta):
                    total += perimeter

        x, y = 2 * x + 3 * y, x + 2 * y


if __name__ == "__main__":
    print(solve())
