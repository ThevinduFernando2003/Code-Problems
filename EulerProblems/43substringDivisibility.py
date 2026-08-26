"""Project Euler Problem 43: Sub-string Divisibility"""

from itertools import permutations


def solve() -> int:
    total = 0

    for perm in permutations("0123456789"):
        if perm[0] == "0":
            continue

        number = "".join(perm)
        if (
            int(number[1:3]) % 2 == 0
            and int(number[2:4]) % 3 == 0
            and int(number[3:5]) % 5 == 0
            and int(number[4:6]) % 7 == 0
            and int(number[5:7]) % 11 == 0
            and int(number[6:8]) % 13 == 0
            and int(number[7:9]) % 17 == 0
        ):
            total += int(number)

    return total


if __name__ == "__main__":
    print(solve())
