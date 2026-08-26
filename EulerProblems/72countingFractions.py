"""Project Euler Problem 72: Counting Fractions"""


def solve(limit: int = 1_000_000) -> int:
    phi = list(range(limit + 1))
    for i in range(2, limit + 1):
        if phi[i] == i:
            for j in range(i, limit + 1, i):
                phi[j] -= phi[j] // i
    return sum(phi[2:])


if __name__ == "__main__":
    print(solve())
