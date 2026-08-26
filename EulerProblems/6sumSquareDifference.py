"""Project Euler Problem 6: Sum Square Difference"""


def solve(n: int = 100) -> int:
    sum_of_numbers = n * (n + 1) // 2
    sum_of_squares = n * (n + 1) * (2 * n + 1) // 6
    return sum_of_numbers ** 2 - sum_of_squares


if __name__ == "__main__":
    print(solve())
