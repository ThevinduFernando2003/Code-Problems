"""Project Euler Problem 9: Special Pythagorean Triplet"""


def solve(perimeter: int = 1000) -> int:
    for a in range(1, perimeter):
        for b in range(a + 1, perimeter - a):
            c = perimeter - a - b
            if c > b and a * a + b * b == c * c:
                return a * b * c
    return 0


if __name__ == "__main__":
    print(solve())
