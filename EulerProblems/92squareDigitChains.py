"""Project Euler Problem 92: Square Digit Chains"""


def next_value(n: int) -> int:
    return sum(int(d) ** 2 for d in str(n))


def solve(limit: int = 10_000_000) -> int:
    cache = {}

    def ends_at_89(n: int) -> bool:
        seen = set()
        while n not in seen and n not in cache:
            seen.add(n)
            n = next_value(n)
        if n in cache:
            result = cache[n]
        else:
            result = n == 89
        for value in seen:
            cache[value] = result
        return result

    return sum(1 for i in range(1, limit) if ends_at_89(i))


if __name__ == "__main__":
    print(solve())
