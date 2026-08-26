"""Project Euler Problem 93: Arithmetic Expressions"""

from itertools import permutations, product, combinations
from operator import add, sub, mul, truediv


OPS = [add, sub, mul, truediv]


def values_for(digits: tuple[int, ...]) -> set[int]:
    results = set()

    for a, b, c, d in permutations(digits):
        for op1, op2, op3 in product(OPS, repeat=3):
            candidates = []
            try:
                candidates.append(op3(op2(op1(a, b), c), d))
                candidates.append(op2(op1(a, b), op3(c, d)))
                candidates.append(op3(op1(a, op2(b, c)), d))
                candidates.append(op1(a, op3(op2(b, c), d)))
                candidates.append(op1(a, op2(b, op3(c, d))))
            except ZeroDivisionError:
                continue

            for value in candidates:
                if abs(value - round(value)) < 1e-9 and value > 0:
                    results.add(int(round(value)))

    return results


def consecutive_length(values: set[int]) -> int:
    n = 1
    while n in values:
        n += 1
    return n - 1


def solve() -> int:
    best_digits = ()
    best_length = 0

    for digits in combinations(range(1, 10), 4):
        length = consecutive_length(values_for(digits))
        if length > best_length:
            best_length = length
            best_digits = digits

    return int("".join(map(str, best_digits)))


if __name__ == "__main__":
    print(solve())
