"""Project Euler Problem 90: Cube Digit Pairs"""

from itertools import combinations


SQUARES = [(0, 1), (0, 4), (0, 9), (1, 6), (2, 5), (3, 6), (4, 9), (6, 4), (8, 1)]


def expand(die: set[int]) -> set[int]:
    faces = set(die)
    if 6 in faces or 9 in faces:
        faces.add(6)
        faces.add(9)
    return faces


def can_form(left: set[int], right: set[int]) -> bool:
    a, b = expand(left), expand(right)
    for x, y in SQUARES:
        if not ((x in a and y in b) or (x in b and y in a)):
            return False
    return True


def solve() -> int:
    dice = list(combinations(range(10), 6))
    count = 0
    for i, left in enumerate(dice):
        for right in dice[i:]:
            if can_form(set(left), set(right)):
                count += 1
    return count


if __name__ == "__main__":
    print(solve())
