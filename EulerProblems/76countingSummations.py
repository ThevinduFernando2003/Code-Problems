"""Project Euler Problem 76: Counting Summations"""


def solve(target: int = 100) -> int:
    ways = [0] * (target + 1)
    ways[0] = 1

    for coin in range(1, target):
        for amount in range(coin, target + 1):
            ways[amount] += ways[amount - coin]

    return ways[target]


if __name__ == "__main__":
    print(solve())
