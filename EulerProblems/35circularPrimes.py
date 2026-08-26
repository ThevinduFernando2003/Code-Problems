"""Project Euler Problem 35: Circular Primes"""


def is_prime(n: int) -> bool:
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True


def rotations(n: int) -> set[int]:
    text = str(n)
    return {int(text[i:] + text[:i]) for i in range(len(text))}


def solve(limit: int = 1_000_000) -> int:
    count = 0
    for number in range(2, limit):
        if all(is_prime(rotated) for rotated in rotations(number)):
            count += 1
    return count


if __name__ == "__main__":
    print(solve())
