"""Project Euler Problem 63: Powerful Digit Counts"""


def solve() -> int:
    count = 0
    for power in range(2, 6):
        n = 1
        while len(str(n**power)) == power:
            count += 1
            n += 1
    return count


if __name__ == "__main__":
    print(solve())
