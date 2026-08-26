"""Project Euler Problem 16: Power Digit Sum"""


def solve(power: int = 1000) -> int:
    return sum(int(digit) for digit in str(2**power))


if __name__ == "__main__":
    print(solve())
