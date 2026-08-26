"""Project Euler Problem 29: Distinct Powers"""


def solve(a_limit: int = 5, b_limit: int = 5) -> int:
    return len({a**b for a in range(2, a_limit + 1) for b in range(2, b_limit + 1)})


if __name__ == "__main__":
    print(solve())
