"""Project Euler Problem 67: Maximum Path Sum II"""

from pathlib import Path


def load_triangle():
    data_file = Path(__file__).with_name("triangle67.txt")
    if data_file.exists():
        return [list(map(int, line.split())) for line in data_file.read_text().splitlines() if line.strip()]
    raise FileNotFoundError("Place triangle67.txt (Project Euler Problem 67 input) in EulerProblems/")


def solve(triangle=None) -> int:
    triangle = triangle or load_triangle()
    best = triangle[-1][:]

    for row in range(len(triangle) - 2, -1, -1):
        for col in range(len(triangle[row])):
            best[col] = triangle[row][col] + max(best[col], best[col + 1])

    return best[0]


if __name__ == "__main__":
    print(solve())
