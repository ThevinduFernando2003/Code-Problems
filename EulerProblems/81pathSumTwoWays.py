"""Project Euler Problem 81: Path Sum Two Ways"""

from pathlib import Path


def load_matrix(name="matrix81.txt"):
    path = Path(__file__).with_name(name)
    if not path.exists():
        raise FileNotFoundError(f"Place {name} in EulerProblems/")
    return [list(map(int, line.split(","))) for line in path.read_text().splitlines()]


def solve(matrix=None):
    matrix = matrix or load_matrix()
    best = matrix[0][:]
    for row in matrix[1:]:
        best[0] += row[0]
        for col in range(1, len(row)):
            best[col] = row[col] + min(best[col], best[col - 1])
    return min(best)


if __name__ == "__main__":
    print(solve())
