"""Project Euler Problem 88: Product-sum Numbers"""


def solve(limit: int = 12_000) -> int:
    numbers = {2: 1}

    def search(current, remaining, product, total, start):
        if remaining == 0:
            if product == total:
                numbers[total] = min(numbers.get(total, total), current)
            return
        for value in range(start, remaining + 1):
            search(current + 1, remaining - value, product * value, total + value, value)

    for total in range(2, limit + 1):
        search(0, total, 1, total, 2)

    return sum(k for k, v in numbers.items() if k <= limit and v == k)


if __name__ == "__main__":
    print(solve())
