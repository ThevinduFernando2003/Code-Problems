"""Project Euler Problem 90: Cube Digit Pairs"""


def solve() -> int:
    cubes = {}
    for n in range(1, 10000):
        key = tuple(sorted(str(n**3)))
        cubes.setdefault(key, []).append(n)

    count = 0
    keys = list(cubes)
    for i, left in enumerate(keys):
        for right in keys[i + 1 :]:
            if len(set("".join(left + right))) == 10:
                count += len(cubes[left]) * len(cubes[right])
    return count


if __name__ == "__main__":
    print(solve())
