"""Project Euler Problem 26: Reciprocal Cycles"""


def cycle_length(denominator: int) -> int:
    remainder = 1
    seen = {}

    for position in range(1, denominator + 1):
        remainder = (remainder * 10) % denominator
        if remainder == 0:
            return 0
        if remainder in seen:
            return position - seen[remainder]
        seen[remainder] = position

    return 0


def solve(limit: int = 1000) -> int:
    best_d = 1
    best_length = 0

    for d in range(2, limit):
        length = cycle_length(d)
        if length > best_length:
            best_length = length
            best_d = d

    return best_d


if __name__ == "__main__":
    print(solve())
