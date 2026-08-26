"""Project Euler Problem 96: Su Doku"""

from pathlib import Path


def parse_grid(text):
    return [list(map(int, line)) for line in text.strip().splitlines()]


def valid(grid, row, col, value):
    if value in grid[row]:
        return False
    if any(grid[r][col] == value for r in range(9)):
        return False
    br, bc = 3 * (row // 3), 3 * (col // 3)
    for r in range(br, br + 3):
        for c in range(bc, bc + 3):
            if grid[r][c] == value:
                return False
    return True


def solve_sudoku(grid):
    for row in range(9):
        for col in range(9):
            if grid[row][col] == 0:
                for value in range(1, 10):
                    if valid(grid, row, col, value):
                        grid[row][col] = value
                        if solve_sudoku(grid):
                            return True
                        grid[row][col] = 0
                return False
    return True


def solve():
    path = Path(__file__).with_name("sudoku.txt")
    if not path.exists():
        raise FileNotFoundError("Place sudoku.txt in EulerProblems/")
    text = path.read_text().split("\n\n")
    total = 0
    for block in text:
        if not block.strip():
            continue
        grid = parse_grid(block)
        solve_sudoku(grid)
        total += grid[0][0] * 100 + grid[0][1] * 10 + grid[0][2]
    return total


if __name__ == "__main__":
    print(solve())
