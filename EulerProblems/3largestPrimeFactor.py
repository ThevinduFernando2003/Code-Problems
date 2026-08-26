"""Project Euler Problem 3: Largest Prime Factor"""


def largest_prime_factor(n: int) -> int:
    factor = 2
    while factor * factor <= n:
        if n % factor == 0:
            n //= factor
        else:
            factor += 1
    return n


if __name__ == "__main__":
    print(largest_prime_factor(600_851_475_143))
