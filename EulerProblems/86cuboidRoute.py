"""Project Euler Problem 86: Cuboid Route"""

from math import isqrt


def solve(target: int = 1_000_000) -> int:
    count = 0
    size = 0

    while count <= target:
        size += 1
        for width_plus_height in range(2, 2 * size + 1):
            squared = size * size + width_plus_height * width_plus_height
            root = isqrt(squared)
            if root * root != squared:
                continue
            low = max(1, width_plus_height - size)
            high = min(width_plus_height // 2, size)
            if high >= low:
                count += high - low + 1

    return size


if __name__ == "__main__":
    print(solve())
