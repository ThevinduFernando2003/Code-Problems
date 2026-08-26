"""Project Euler Problem 18: Maximum Path Sum I"""

TRIANGLE = [
    [75],
    [95, 64],
    [17, 47, 82],
    [18, 35, 87, 10],
    [20, 4, 82, 47, 65],
    [19, 1, 23, 75, 3, 34],
    [88, 2, 77, 73, 15, 3, 98],
    [10, 7, 57, 9, 98, 52, 88, 61],
    [20, 37, 2, 56, 8, 70, 59, 17, 41],
    [41, 46, 34, 54, 73, 82, 25, 39, 27, 58],
    [70, 28, 75, 16, 73, 33, 54, 5, 78, 59, 42],
    [41, 36, 72, 25, 39, 73, 45, 18, 9, 46, 17, 46],
    [29, 47, 24, 3, 44, 71, 37, 26, 50, 24, 44, 57, 95],
    [53, 8, 56, 54, 83, 27, 97, 66, 96, 35, 16, 47, 55, 30],
    [98, 78, 43, 15, 25, 23, 57, 5, 54, 71, 31, 26, 8, 53, 46, 26, 47],
]


def solve(triangle=TRIANGLE) -> int:
    best = triangle[-1][:]

    for row in range(len(triangle) - 2, -1, -1):
        for col in range(len(triangle[row])):
            best[col] = triangle[row][col] + max(best[col], best[col + 1])

    return best[0]


if __name__ == "__main__":
    print(solve())
