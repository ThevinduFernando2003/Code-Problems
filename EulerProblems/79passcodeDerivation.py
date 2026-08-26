"""Project Euler Problem 79: Passcode Derivation"""

from itertools import permutations
from pathlib import Path


def solve() -> str:
    keylog = Path(__file__).with_name("keylog.txt")
    if not keylog.exists():
        raise FileNotFoundError("Place keylog.txt in EulerProblems/")

    pairs = []
    for line in keylog.read_text().splitlines():
        a, b, c = map(int, line.strip())
        pairs.extend([(a, b), (b, c)])

    for perm in permutations(range(10)):
        order = {digit: index for index, digit in enumerate(perm)}
        if all(order[a] < order[b] for a, b in pairs):
            return "".join(str(d) for d in perm)

    return ""


if __name__ == "__main__":
    print(solve())
