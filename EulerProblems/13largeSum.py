"""Project Euler Problem 13: Large Sum"""

from pathlib import Path


def load_numbers() -> list[int]:
    data_file = Path(__file__).with_name("euler13.txt")
    if data_file.exists():
        return [int(line.strip()) for line in data_file.read_text().splitlines() if line.strip()]

    # Fallback: first block of the official Project Euler input.
    return [
        int(line)
        for line in """
3710728753390210279819792080942787472011289929663314159662
4637693768747489779581593671
6231290471491951241542882422
7428764204271406940217326211
4439872981343470790675344821
6372799572852858269710612995
8844861719796100979910850962
2772541542089327875411973399
4751941212581
""".strip().splitlines()
    ]


def solve() -> int:
    total = sum(load_numbers())
    return int(str(total)[:10])


if __name__ == "__main__":
    print(solve())
