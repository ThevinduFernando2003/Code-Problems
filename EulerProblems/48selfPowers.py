"""Project Euler Problem 48: Self Powers"""


def solve(last: int = 1000) -> int:
    return sum(power**power for power in range(1, last + 1)) % 10**10


if __name__ == "__main__":
    print(solve())
