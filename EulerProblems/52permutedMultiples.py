"""Project Euler Problem 52: Permuted Multiples"""


def solve() -> int:
    n = 1
    while True:
        if all(sorted(str(n)) == sorted(str(n * multiplier)) for multiplier in range(2, 7)):
            return n
        n += 1


if __name__ == "__main__":
    print(solve())
