"""Project Euler Problem 78: Coin Partitions"""

MOD = 1_000_000


def solve() -> int:
    ways = [0] * 100_001
    ways[0] = 1

    for coin in range(1, 100_001):
        for amount in range(coin, 100_001):
            ways[amount] = (ways[amount] + ways[amount - coin]) % MOD
            if ways[amount] % 1_000_000 == 0:
                return coin

    return 0


if __name__ == "__main__":
    print(solve())
