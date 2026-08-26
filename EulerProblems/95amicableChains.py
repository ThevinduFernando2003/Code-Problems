"""Project Euler Problem 95: Amicable Chains"""


def proper_divisor_sum(n: int) -> int:
    total = 1
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            total += i
            if i * i != n:
                total += n // i
    return total


def solve(limit: int = 1_000_000) -> int:
    cache = {0: 0, 1: 0}
    best = (0, 0)

    for start in range(2, limit + 1):
        chain = []
        current = start
        while current not in cache and current not in chain and current <= limit:
            chain.append(current)
            current = proper_divisor_sum(current)

        length = 0
        if current in cache:
            length = cache[current]
        elif current in chain:
            index = chain.index(current)
            length = len(chain) - index
            for pos, value in enumerate(chain[index:], start=length):
                cache[value] = pos

        for value in chain:
            cache[value] = length

        if length > best[0]:
            best = (length, min(chain) if chain else 0)

    return best[1]


if __name__ == "__main__":
    print(solve())
