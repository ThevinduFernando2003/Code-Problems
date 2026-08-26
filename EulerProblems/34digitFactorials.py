"""Project Euler Problem 34: Digit Factorials"""


def factorial(n: int) -> int:
    result = 1
    for i in range(2, n + 1):
        result *= i
    return result


def digit_factorial_sum(n: int) -> int:
    return sum(factorial(int(digit)) for digit in str(n))


def solve() -> int:
    return sum(number for number in range(10, 50_000) if number == digit_factorial_sum(number))


if __name__ == "__main__":
    print(solve())
