"""Project Euler Problem 100: Arranged Probability"""

from math import comb


def solve() -> int:
    for total in range(100, 10_000):
        blue = 0
        for b in range(1, total):
            if comb(b, 2) / comb(total, 2) == 0.5:
                blue = b
                break
        if blue and comb(blue - 1, 2) / comb(total - 1, 2) == 1 / 3:
            return total
    return 0


if __name__ == "__main__":
    print(solve())
