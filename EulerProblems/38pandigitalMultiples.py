"""Project Euler Problem 38: Pandigital Multiples"""


def is_pandigital(text: str, digits: str = "123456789") -> bool:
    return len(text) == len(digits) and sorted(text) == sorted(digits)


def solve() -> int:
    best = 0

    for number in range(1, 10_000):
        concatenated = ""
        valid = True
        for multiplier in range(1, 10):
            concatenated += str(number * multiplier)
            if len(concatenated) > 9:
                valid = False
                break
        if valid and len(concatenated) == 9 and is_pandigital(concatenated):
            best = max(best, int(concatenated))

    return best


if __name__ == "__main__":
    print(solve())
