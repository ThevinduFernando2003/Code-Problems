"""Project Euler Problem 40: Champernowne's Constant"""


def champernowne_digit(index: int) -> int:
    length = 1
    count = 9
    start = 1

    while index > length * count:
        index -= length * count
        length += 1
        count *= 10
        start *= 10

    number = start + (index - 1) // length
    digit_index = (index - 1) % length
    return int(str(number)[digit_index])


def solve() -> int:
    product = 1
    for power in range(7):
        product *= champernowne_digit(10**power)
    return product


if __name__ == "__main__":
    print(solve())
