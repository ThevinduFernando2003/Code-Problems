"""Project Euler Problem 36: Double-base Palindromes"""


def is_palindrome(value: int, base: int) -> bool:
    digits = []
    n = value
    while n:
        digits.append(n % base)
        n //= base
    return digits == digits[::-1]


def solve(limit: int = 1_000_000) -> int:
    return sum(number for number in range(1, limit) if is_palindrome(number, 10) and is_palindrome(number, 2))


if __name__ == "__main__":
    print(solve())
