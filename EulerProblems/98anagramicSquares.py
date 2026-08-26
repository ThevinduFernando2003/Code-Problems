"""Project Euler Problem 98: Anagramic Squares"""

from collections import defaultdict
from itertools import permutations
from math import isqrt
from pathlib import Path


def load_words():
    path = Path(__file__).with_name("words98.txt")
    if not path.exists():
        raise FileNotFoundError("Place words98.txt in EulerProblems/")
    return [word.strip('"') for word in path.read_text().split(",")]


def solve():
    words = load_words()
    groups = defaultdict(list)
    for word in words:
        groups[tuple(sorted(word))].append(word)

    best = 0
    for anagrams in groups.values():
        if len(anagrams) < 2:
            continue
        length = len(anagrams[0])
        squares = {str(n * n) for n in range(isqrt(10**length) + 1, isqrt(10 ** (length + 1)))}
        for left, right in permutations(anagrams, 2):
            for square in squares:
                if sorted(square) == sorted(left) and sorted(square) == sorted(right):
                    best = max(best, int(left) * int(right))
    return best


if __name__ == "__main__":
    print(solve())
