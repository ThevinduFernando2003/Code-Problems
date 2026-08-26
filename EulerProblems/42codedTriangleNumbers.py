"""Project Euler Problem 42: Coded Triangle Numbers"""

from pathlib import Path


def is_triangle(value: int) -> bool:
    root = int((8 * value + 1) ** 0.5)
    return root * root == 8 * value + 1


def word_score(word: str) -> int:
    return sum(ord(ch) - ord("A") + 1 for ch in word)


def load_words() -> list[str]:
    words_file = Path(__file__).with_name("words.txt")
    if not words_file.exists():
        raise FileNotFoundError(
            "Download words.txt from https://projecteuler.net/project/words.txt "
            "and place it in the EulerProblems folder."
        )
    return [word.strip('"') for word in words_file.read_text().split(",")]


def solve() -> int:
    return sum(1 for word in load_words() if is_triangle(word_score(word)))


if __name__ == "__main__":
    print(solve())
