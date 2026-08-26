"""Project Euler Problem 30: Digit Fifth Powers"""


def digit_power_sum(n: int, power: int = 5) -> int:
    return sum(int(digit) ** power for digit in str(n))


def solve(power: int = 5) -> int:
    upper = 9**power * (power + 1)
    return sum(number for number in range(2, upper) if number == digit_power_sum(number, power))


if __name__ == "__main__":
    print(solve())
