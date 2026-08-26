"""Project Euler Problem 82: Path Sum Three Ways"""

from heapq import heappush, heappop
from pathlib import Path


def load_matrix():
    path = Path(__file__).with_name("matrix82.txt")
    if not path.exists():
        raise FileNotFoundError("Place matrix82.txt in EulerProblems/")
    return [list(map(int, line.split(","))) for line in path.read_text().splitlines()]


def solve(matrix=None):
    matrix = matrix or load_matrix()
    rows, cols = len(matrix), len(matrix[0])
    pq = [(matrix[r][0], r, 0) for r in range(rows)]
    seen = set()

    while pq:
        cost, row, col = heappop(pq)
        if col == cols - 1:
            return cost
        if (row, col) in seen:
            continue
        seen.add((row, col))
        if row + 1 < rows:
            heappush(pq, (cost + matrix[row + 1][col], row + 1, col))
        if row > 0:
            heappush(pq, (cost + matrix[row - 1][col], row - 1, col))
        if col + 1 < cols:
            heappush(pq, (cost + matrix[row][col + 1], row, col + 1))
    return 0


if __name__ == "__main__":
    print(solve())
