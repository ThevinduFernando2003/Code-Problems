"""Project Euler Problem 22: Names Scores"""

from pathlib import Path


def letter_score(name: str) -> int:
    return sum(ord(ch) - ord("A") + 1 for ch in name)


def load_names() -> list[str]:
    names_file = Path(__file__).with_name("names.txt")
    if not names_file.exists():
        raise FileNotFoundError(
            "Download names.txt from https://projecteuler.net/project/names.txt "
            "and place it in the EulerProblems folder."
        )
    return sorted(name.strip('"') for name in names_file.read_text().split(","))


def solve() -> int:
    return sum((index + 1) * letter_score(name) for index, name in enumerate(load_names()))


if __name__ == "__main__":
    print(solve())
