"""Project Euler Problem 1: Multiples of 3 or 5"""


def solve(limit: int = 1000) -> int:
    return sum(i for i in range(limit) if i % 3 == 0 or i % 5 == 0)


if __name__ == "__main__":
    print(solve())
