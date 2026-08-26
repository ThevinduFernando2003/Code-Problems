"""Project Euler Problem 68: Magic 5-gon Ring"""

import itertools


def solve() -> int:
    best = 0

    for perm in itertools.permutations(range(1, 11)):
        outer = perm[:5]
        inner = perm[5:]

        lines = [
            (outer[0], inner[0], inner[1]),
            (outer[1], inner[1], inner[2]),
            (outer[2], inner[2], inner[3]),
            (outer[3], inner[3], inner[4]),
            (outer[4], inner[4], inner[0]),
        ]

        sums = {sum(line) for line in lines}
        if len(sums) != 1:
            continue

        min_outer = min(range(5), key=lambda i: outer[i])
        rotated = lines[min_outer:] + lines[:min_outer]
        digits = "".join(str(x) for line in rotated for x in line)
        if len(digits) == 14:
            best = max(best, int(digits))

    return best


if __name__ == "__main__":
    print(solve())
