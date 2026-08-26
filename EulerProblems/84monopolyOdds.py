"""Project Euler Problem 84: Monopoly Odds"""

from collections import Counter


def solve(turns: int = 10**6) -> int:
    board = [
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    ]
    jail = 10
    g2j = 30
    cc = [2, 17, 33]
    ch = [7, 22, 36]

    counts = Counter()
    pos = 0
    doubles = 0

    import random

    random.seed(0)
    for _ in range(turns):
        d1, d2 = random.randint(1, 6), random.randint(1, 6)
        if d1 == d2:
            doubles += 1
            if doubles == 3:
                pos = jail
                doubles = 0
                counts[pos] += 1
                continue
        else:
            doubles = 0

        pos = (pos + d1 + d2) % 40
        if pos == g2j:
            pos = jail
        elif pos in cc or pos in ch:
            pass
        counts[pos] += 1

    top = counts.most_common(1)[0][0]
    return top


if __name__ == "__main__":
    print(solve())
