"""Project Euler Problem 25: 1000-digit Fibonacci Number"""


def solve(digits: int = 1000) -> int:
    a, b = 1, 1
    index = 2

    while len(str(b)) < digits:
        a, b = b, a + b
        index += 1

    return index


if __name__ == "__main__":
    print(solve())
