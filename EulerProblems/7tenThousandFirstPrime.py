"""Project Euler Problem 7: 10 001st Prime"""


def nth_prime(n: int) -> int:
    count = 0
    candidate = 1

    while count < n:
        candidate += 1
        if all(candidate % d for d in range(2, int(candidate ** 0.5) + 1)):
            count += 1

    return candidate


if __name__ == "__main__":
    print(nth_prime(10_001))
