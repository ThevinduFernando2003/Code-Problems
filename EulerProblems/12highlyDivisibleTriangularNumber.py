"""Project Euler Problem 12: Highly Divisible Triangular Number"""


def divisor_count(n: int) -> int:
    count = 0
    i = 1
    while i * i <= n:
        if n % i == 0:
            count += 2 if i * i != n else 1
        i += 1
    return count


def solve(min_divisors: int = 500) -> int:
    n = 1
    triangle = 1

    while True:
        n += 1
        triangle += n
        if divisor_count(triangle) > min_divisors:
            return triangle


if __name__ == "__main__":
    print(solve())
