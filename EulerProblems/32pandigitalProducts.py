"""Project Euler Problem 32: Pandigital Products"""


def is_pandigital(text: str, digits: str = "123456789") -> bool:
    return sorted(text) == sorted(digits)


def solve() -> int:
    total = 0
    seen = set()

    for multiplicand in range(1, 10000):
        for multiplier in range(1, 1000):
            product = multiplicand * multiplier
            combined = f"{multiplicand}{multiplier}{product}"
            if len(combined) == 9 and is_pandigital(combined) and combined not in seen:
                seen.add(combined)
                total += product

    return total


if __name__ == "__main__":
    print(solve())
