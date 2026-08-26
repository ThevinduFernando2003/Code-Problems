"""Project Euler Problem 55: Lychrel Numbers"""


def is_palindrome(value: int) -> bool:
    text = str(value)
    return text == text[::-1]


def is_lychrel(value: int, steps: int = 50) -> bool:
    current = value
    for _ in range(steps):
        current += int(str(current)[::-1])
        if is_palindrome(current):
            return False
    return True


def solve(limit: int = 10_000) -> int:
    return sum(1 for number in range(1, limit) if is_lychrel(number))


if __name__ == "__main__":
    print(solve())
