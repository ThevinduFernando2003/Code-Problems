"""Project Euler Problem 78: Coin Partitions"""


def solve(modulus: int = 1_000_000) -> int:
    partitions = [1]
    n = 1

    while True:
        total = 0
        k = 1
        while True:
            pentagonal1 = k * (3 * k - 1) // 2
            pentagonal2 = k * (3 * k + 1) // 2
            if pentagonal1 > n:
                break
            sign = 1 if k % 2 == 1 else -1
            total += sign * partitions[n - pentagonal1]
            if pentagonal2 <= n:
                total += sign * partitions[n - pentagonal2]
            k += 1

        value = total % modulus
        partitions.append(value)
        if value == 0:
            return n
        n += 1


if __name__ == "__main__":
    print(solve())
