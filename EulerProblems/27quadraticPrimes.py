"""Project Euler Problem 27: Quadratic Primes"""


def is_prime(n: int) -> bool:
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True


def consecutive_primes(a: int, b: int) -> int:
    length = 0
    n = 0
    while is_prime(n * n + a * n + b):
        length += 1
        n += 1
    return length


def solve(limit: int = 1000) -> int:
    best_a = 0
    best_b = 0
    best_length = 0

    for a in range(-limit, limit):
        for b in range(2 - limit, limit):
            if not is_prime(abs(b)):
                continue

            length = consecutive_primes(a, b)
            if length > best_length:
                best_length = length
                best_a = a
                best_b = b

    return best_a * best_b


if __name__ == "__main__":
    print(solve())
