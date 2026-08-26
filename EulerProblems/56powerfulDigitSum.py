"""Project Euler Problem 56: Powerful Digit Sum"""


def solve() -> int:
    return max(
        sum(int(digit) for digit in str(base**power))
        for base in range(2, 100)
        for power in range(2, 100)
    )


if __name__ == "__main__":
    print(solve())
