"""Project Euler Problem 99: Largest Exponential"""

from pathlib import Path


def solve():
    path = Path(__file__).with_name("base_exp.txt")
    if not path.exists():
        raise FileNotFoundError("Place base_exp.txt in EulerProblems/")
    best_line = 0
    best_value = float("-inf")
    for index, line in enumerate(path.read_text().splitlines(), start=1):
        base, exp = map(int, line.split(","))
        value = exp * __import__("math").log(base)
        if value > best_value:
            best_value = value
            best_line = index
    return best_line


if __name__ == "__main__":
    print(solve())
