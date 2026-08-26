"""Project Euler Problem 81: Path Sum Two Ways"""

from pathlib import Path


def load_matrix(name="matrix81.txt"):
    path = Path(__file__).with_name(name)
    if not path.exists():
        raise FileNotFoundError(f"Place {name} in EulerProblems/")
    return [list(map(int, line.split(","))) for line in path.read_text().splitlines() if line.strip()]


def solve(matrix=None):
    matrix = matrix or load_matrix()
    rows = len(matrix)
    cols = len(matrix[0])
    dp = [row[:] for row in matrix]

    for col in range(1, cols):
        dp[0][col] += dp[0][col - 1]
    for row in range(1, rows):
        dp[row][0] += dp[row - 1][0]

    for row in range(1, rows):
        for col in range(1, cols):
            dp[row][col] += min(dp[row - 1][col], dp[row][col - 1])

    return dp[-1][-1]


if __name__ == "__main__":
    print(solve())
