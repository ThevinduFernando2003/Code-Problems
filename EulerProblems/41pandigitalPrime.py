"""Project Euler Problem 41: Pandigital Prime"""


def is_prime(n: int) -> bool:
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True


def solve() -> int:
    from itertools import permutations

    for length in range(9, 0, -1):
        digits = "".join(str(d) for d in range(length, 0, -1))
        for perm in permutations(digits):
            number = int("".join(perm))
            if is_prime(number):
                return number

    return 0


if __name__ == "__main__":
    print(solve())
