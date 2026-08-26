"""Project Euler Problem 53: Combinatoric Selections"""

MOD = 10**9 + 7


def ncr(n: int, r: int, fact: list[int], inv: list[int]) -> int:
    return fact[n] * inv[r] % MOD * inv[n - r] % MOD


def solve(limit: int = 1_000_000, choose: int = 1000) -> int:
    fact = [1] * (choose + 1)
    for i in range(1, choose + 1):
        fact[i] = fact[i - 1] * i % MOD

    inv = [1] * (choose + 1)
    inv[choose] = pow(fact[choose], MOD - 2, MOD)
    for i in range(choose, 0, -1):
        inv[i - 1] = inv[i] * i % MOD

    return sum(ncr(n + choose, choose, fact, inv) > limit for n in range(1, 2001))


if __name__ == "__main__":
    print(solve())
