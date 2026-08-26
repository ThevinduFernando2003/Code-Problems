"""Project Euler Problem 46: Goldbach's Other Conjecture"""


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
    candidate = 9
    while True:
        if candidate % 2 == 0:
            candidate += 1
            continue

        found = False
        for square in range(1, int(candidate**0.5) + 1):
            remainder = candidate - 2 * square * square
            if remainder > 0 and is_prime(remainder):
                found = True
                break

        if not found:
            return candidate

        candidate += 2


if __name__ == "__main__":
    print(solve())
