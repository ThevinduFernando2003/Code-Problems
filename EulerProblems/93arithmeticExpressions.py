"""Project Euler Problem 93: Arithmetic Expressions"""

import itertools


def evaluate(numbers, operators):
    values = [numbers[0]]
    for op, number in zip(operators, numbers[1:]):
        if op == "+":
            values.append(number)
        elif op == "-":
            values.append(-number)
        else:
            values[-1] *= number
    return sum(values)


def solve() -> int:
    digits = "123456789"
    longest = 0

    for perm in itertools.permutations(digits):
        numbers = [int(ch) for ch in perm]
        for pattern in itertools.product("+*", repeat=8):
            value = evaluate(numbers, pattern)
            if value <= 0:
                continue
            if value == longest + 1:
                longest = value
            elif value > longest + 1:
                break
    return longest


if __name__ == "__main__":
    print(solve())
