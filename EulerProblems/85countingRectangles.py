"""Project Euler Problem 85: Counting Rectangles"""


def solve(limit: int = 2_000_000) -> int:
    best_area = 0
    best_diff = float("inf")

    for width in range(1, 2001):
        for height in range(1, width + 1):
            count = width * (width + 1) * height * (height + 1) // 4
            diff = abs(count - limit)
            area = width * height
            if diff < best_diff or (diff == best_diff and area > best_area):
                best_diff = diff
                best_area = area

    return best_area


if __name__ == "__main__":
    print(solve())
