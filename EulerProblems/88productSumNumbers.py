"""Project Euler Problem 88: Product-sum Numbers"""


def solve(limit: int = 12_000) -> int:
    max_n = 2 * limit
    minimal = [10**18] * (limit + 1)

    def search(product: int, total: int, factors: int, start: int) -> None:
        ones_needed = product - total
        k = factors + ones_needed
        if 2 <= k <= limit:
            minimal[k] = min(minimal[k], product)

        i = start
        while product * i <= max_n:
            search(product * i, total + i, factors + 1, i)
            i += 1

    search(1, 0, 0, 2)
    return sum(set(minimal[2:]))


if __name__ == "__main__":
    print(solve())
