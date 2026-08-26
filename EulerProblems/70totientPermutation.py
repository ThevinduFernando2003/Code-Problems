"""Project Euler Problem 70: Totient Permutation"""


def solve(limit: int = 10_000_000) -> int:
    phi = list(range(limit))
    for i in range(2, limit):
        if phi[i] == i:
            for j in range(i, limit, i):
                phi[j] -= phi[j] // i

    best_n = 0
    best_ratio = float("inf")
    for n in range(2, limit):
        value = phi[n]
        if sorted(str(n)) == sorted(str(value)):
            ratio = n / value
            if ratio < best_ratio:
                best_ratio = ratio
                best_n = n
    return best_n


if __name__ == "__main__":
    print(solve())
