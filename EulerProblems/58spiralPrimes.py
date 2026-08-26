"""Project Euler Problem 58: Spiral Primes"""


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
    primes = 0
    total = 1
    value = 1
    side = 1

    while True:
        side += 2
        for _ in range(4):
            value += side - 1
            total += 1
            if is_prime(value):
                primes += 1

        if side > 1 and primes / total < 0.1:
            return side


if __name__ == "__main__":
    print(solve())
