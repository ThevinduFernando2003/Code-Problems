"""Project Euler Problem 11: Largest Product in a Grid"""

GRID = [
    list(map(int, row.split()))
    for row in """
08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
81 49 31 73 55 26 54 19 79 00 08 51 26 08 00 25 11 88 13 17
04 89 97 77 31 84 02 00 32 84 94 81 98 57 07 23 09 70 98 73
93 85 82 22 83 45 32 11 47 21 84 04 22 68 70 02 02 45 65 94
80 08 62 03 28 59 99 86 56 68 89 68 55 54 66 73 92 71 76 88
81 40 23 71 87 28 48 19 96 76 84 37 32 85 16 97 96 13 32 25
01 90 43 51 97 28 99 05 40 08 97 07 46 62 04 67 81 37 32 40
69 34 24 05 82 56 03 48 95 94 81 99 45 20 11 04 96 05 41 48
43 60 92 25 94 43 77 27 65 75 41 07 39 82 95 77 05 02 36 62
86 66 03 44 94 35 73 85 46 02 76 59 51 86 06 01 03 94 43 06
67 42 75 87 97 48 72 01 94 32 36 29 78 08 28 34 32 08 45 94
87 62 98 27 23 09 70 98 73 93 38 53 60 04 54 76 63 45 91 04
64 47 42 49 19 87 83 45 95 96 53 83 58 06 93 28 89 94 95 81
79 52 62 04 82 86 58 73 40 31 80 87 97 59 98 50 08 58 48 87
08 48 42 87 55 64 50 85 43 64 98 39 87 86 09 51 52 60 70 95
48 64 58 43 55 83 72 45 83 94 98 57 87 97 94 32 77 97 02 72
16 08 76 98 89 34 65 39 99 59 89 92 84 83 96 99 34 65 78 97
27 17 98 79 20 75 53 28 84 69 36 73 75 29 91 96 65 93 75 82
88 41 28 91 32 40 62 20 82 05 14 58 77 27 61 82 52 74 65 67
61 07 91 56 75 33 78 36 29 75 46 92 91 62 94 87 84 67 46 75
""".strip().splitlines()
]


def product(values):
    result = 1
    for value in values:
        result *= value
    return result


def solve() -> int:
    rows = len(GRID)
    cols = len(GRID[0])
    best = 0

    for row in range(rows):
        for col in range(cols):
            if col + 3 < cols:
                best = max(best, product(GRID[row][col : col + 4]))
            if row + 3 < rows:
                best = max(best, product(GRID[row + k][col] for k in range(4)))
            if row + 3 < rows and col + 3 < cols:
                best = max(best, product(GRID[row + k][col + k] for k in range(4)))
            if row - 3 >= 0 and col + 3 < cols:
                best = max(best, product(GRID[row - k][col + k] for k in range(4)))

    return best


if __name__ == "__main__":
    print(solve())
