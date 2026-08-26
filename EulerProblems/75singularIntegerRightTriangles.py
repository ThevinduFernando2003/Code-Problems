"""Project Euler Problem 75: Singular Integer Right Triangles"""


def solve(limit: int = 1_500_000) -> int:
    counts = [0] * (limit + 1)

    m_limit = int((limit / 2) ** 0.5) + 1
    for m in range(2, m_limit):
        for n in range(1, m):
            if (m - n) % 2 == 1 and math_gcd(m, n) == 1:
                perimeter = 2 * m * (m + n)
                for k in range(perimeter, limit + 1, perimeter):
                    counts[k] += 1

    return sum(1 for value in counts if value == 1)


def math_gcd(a: int, b: int) -> int:
    while b:
        a, b = b, a % b
    return a


if __name__ == "__main__":
    print(solve())
