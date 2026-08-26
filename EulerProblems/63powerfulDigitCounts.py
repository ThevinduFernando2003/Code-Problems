"""Project Euler Problem 63: Powerful Digit Counts"""


def solve() -> int:
    count = 0
    for power in range(1, 22):
        for base in range(1, 10):
            if len(str(base**power)) == power:
                count += 1
    return count


if __name__ == "__main__":
    print(solve())
