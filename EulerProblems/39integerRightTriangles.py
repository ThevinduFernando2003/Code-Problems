"""Project Euler Problem 39: Integer Right Triangles"""


def solve(limit: int = 1000) -> int:
    best_perimeter = 0
    best_count = 0

    for perimeter in range(3, limit + 1):
        count = 0
        for a in range(1, perimeter // 3 + 1):
            for b in range(a, (perimeter - a) // 2 + 1):
                c = perimeter - a - b
                if a * a + b * b == c * c:
                    count += 1

        if count > best_count:
            best_count = count
            best_perimeter = perimeter

    return best_perimeter


if __name__ == "__main__":
    print(solve())
