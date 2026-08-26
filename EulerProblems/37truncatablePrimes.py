"""Project Euler Problem 37: Truncatable Primes"""


def is_prime(n: int) -> bool:
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True


def is_truncatable(n: int) -> bool:
    text = str(n)
    for i in range(1, len(text)):
        if not is_prime(int(text[i:])):
            return False
        if not is_prime(int(text[: len(text) - i])):
            return False
    return True


def solve(count_needed: int = 11) -> int:
    total = 0
    found = 0
    number = 10

    while found < count_needed:
        if is_prime(number) and is_truncatable(number):
            total += number
            found += 1
        number += 1

    return total


if __name__ == "__main__":
    print(solve())
