"""Project Euler Problem 4: Largest Palindrome Product"""


def is_palindrome(value: int) -> bool:
    text = str(value)
    return text == text[::-1]


def solve(low: int = 100, high: int = 999) -> int:
    best = 0
    for i in range(high, low - 1, -1):
        for j in range(i, low - 1, -1):
            product = i * j
            if product <= best:
                break
            if is_palindrome(product):
                best = product
    return best


if __name__ == "__main__":
    print(solve())
