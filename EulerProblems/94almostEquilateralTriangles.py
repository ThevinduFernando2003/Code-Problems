"""Project Euler Problem 94: Almost Equilateral Triangles"""


def solve(limit: int = 1_000_000_000) -> int:
    perimeters = []
    a, b = 1, 1
    while True:
        a, b = 4 * b - a, a
        perimeter = 3 * b - 1
        if perimeter > limit:
            break
        perimeters.append(perimeter)
        perimeter = 3 * b + 1
        if perimeter > limit:
            break
        perimeters.append(perimeter)
    return sum(perimeters)


if __name__ == "__main__":
    print(solve())
