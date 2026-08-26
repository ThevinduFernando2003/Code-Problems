"""Project Euler Problem 51: Prime Digit Replacements"""


def is_prime(n: int) -> bool:
    if n < 2:
        return False
    if n % 2 == 0:
        return n == 2
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True


def solve(family_size: int = 8) -> int:
    n = 10
    while True:
        if not is_prime(n):
            n += 1
            continue

        digits = str(n)
        for position in range(len(digits)):
            for replacement in "0123456789":
                if position == 0 and replacement == "0":
                    continue

                family = 0
                for digit in "0123456789":
                    if position == 0 and digit == "0":
                        continue
                    candidate = list(digits)
                    candidate[position] = digit
                    if is_prime(int("".join(candidate))):
                        family += 1

                if family == family_size:
                    return n
        n += 1


if __name__ == "__main__":
    print(solve())
