"""Project Euler Problem 66: Diophantine Equation"""


def fundamental_solution(d: int) -> tuple[int, int]:
    m = 0
    d0 = 1
    a0 = int(d**0.5)
    a = a0
    p_prev, p = 1, a0
    q_prev, q = 0, 1

    while True:
        m = d0 * a - m
        d0 = (d - m * m) // d0
        a = (a0 + m) // d0
        p, p_prev = a * p + p_prev, p
        q, q_prev = a * q + q_prev, q
        if p * p - d * q * q == 1:
            return p, q


def solve(limit: int = 1000) -> int:
    best_d = 0
    best_x = 0

    for d in range(2, limit + 1):
        if int(d**0.5) ** 2 == d:
            continue
        x, _ = fundamental_solution(d)
        if x > best_x:
            best_x = x
            best_d = d

    return best_d


if __name__ == "__main__":
    print(solve())
