"""Project Euler Problem 97: Large Non-Mersenne Prime"""


def solve() -> int:
    return (28433 * pow(2, 7_830_457, 10**10) + 1) % 10**10


if __name__ == "__main__":
    print(solve())
