"""Project Euler Problem 83: Path Sum Four Ways"""

from heapq import heappush, heappop
from pathlib import Path


def load_matrix():
    path = Path(__file__).with_name("matrix83.txt")
    if not path.exists():
        raise FileNotFoundError("Place matrix83.txt in EulerProblems/")
    return [list(map(int, line.split(","))) for line in path.read_text().splitlines()]


def solve(matrix=None):
    matrix = matrix or load_matrix()
    rows, cols = len(matrix), len(matrix[0])
    pq = [(matrix[0][0], 0, 0)]
    best = {}

    while pq:
        cost, row, col = heappop(pq)
        if row == rows - 1 and col == cols - 1:
            return cost
        if best.get((row, col), float("inf")) < cost:
            continue
        best[(row, col)] = cost
        for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            nr, nc = row + dr, col + dc
            if 0 <= nr < rows and 0 <= nc < cols:
                heappush(pq, (cost + matrix[nr][nc], nr, nc))
    return 0


if __name__ == "__main__":
    print(solve())
