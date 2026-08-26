"""Project Euler Problem 86: Cuboid Route"""


def solve(limit: int = 1_000_000) -> int:
    m = 1
    while True:
        count = 0
        for width in range(1, m + 1):
            for height in range(width, m + 1):
                shortest = (m * m + height * height) ** 0.5
                if abs(shortest - round(shortest)) < 1e-9:
                    count += 1
        if count > limit:
            return m
        m += 1


if __name__ == "__main__":
    print(solve())
