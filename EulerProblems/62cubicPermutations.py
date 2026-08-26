"""Project Euler Problem 62: Cubic Permutations"""


def solve(group_size: int = 5) -> int:
    cubes = {}
    n = 1

    while True:
        cube = n**3
        key = "".join(sorted(str(cube)))
        cubes.setdefault(key, []).append(n)
        if len(cubes[key]) == group_size:
            return min(cubes[key])
        n += 1


if __name__ == "__main__":
    print(solve())
