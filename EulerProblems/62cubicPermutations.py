"""Project Euler Problem 62: Cubic Permutations"""

from collections import defaultdict


def solve(group_size: int = 5) -> int:
    groups: dict[str, list[int]] = defaultdict(list)
    n = 1

    while True:
        cube = n**3
        key = "".join(sorted(str(cube)))
        groups[key].append(cube)
        if len(groups[key]) == group_size:
            return min(groups[key])
        n += 1


if __name__ == "__main__":
    print(solve())
