"""Project Euler Problem 91: Right Triangles Integer Coordinates"""


def solve(limit: int = 50) -> int:
    count = 0
    for x2 in range(limit + 1):
        for y2 in range(limit + 1):
            if x2 == 0 and y2 == 0:
                continue
            d2 = x2 * x2 + y2 * y2
            for x3 in range(limit + 1):
                for y3 in range(limit + 1):
                    if (x3, y3) in ((0, 0), (x2, y2)):
                        continue
                    if x2 * y3 - y2 * x3 == 0:
                        continue
                    d1 = x3 * x3 + y3 * y3
                    d3 = (x3 - x2) ** 2 + (y3 - y2) ** 2
                    if d1 + d2 == d3 or d1 + d3 == d2 or d2 + d3 == d1:
                        count += 1
    return count // 2


if __name__ == "__main__":
    print(solve())
