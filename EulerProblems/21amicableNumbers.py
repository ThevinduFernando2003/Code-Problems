"""Project Euler Problem 21: Amicable Numbers"""


def proper_divisor_sum(n: int) -> int:
    total = 1
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            total += i
            if i * i != n:
                total += n // i
    return total


def solve(limit: int = 10_000) -> int:
    total = 0
    cache = [0] * limit

    for number in range(2, limit):
        cache[number] = proper_divisor_sum(number)

    for a in range(2, limit):
        b = cache[a]
        if b > a and b < limit and cache[b] == a:
            total += a + b

    return total


if __name__ == "__main__":
    print(solve())
