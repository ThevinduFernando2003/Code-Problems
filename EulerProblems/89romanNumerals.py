"""Project Euler Problem 89: Roman Numerals"""

from pathlib import Path

VALUES = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
SUBTRACT = {"IV", "IX", "XL", "XC", "CD", "CM"}


def to_int(roman: str) -> int:
    total = 0
    previous = 0
    for ch in reversed(roman):
        value = VALUES[ch]
        if value < previous:
            total -= value
        else:
            total += value
            previous = value
    return total


def to_roman(number: int) -> str:
    pairs = [
        (1000, "M"), (900, "CM"), (500, "D"), (400, "CD"),
        (100, "C"), (90, "XC"), (50, "L"), (40, "XL"),
        (10, "X"), (9, "IX"), (5, "V"), (4, "IV"), (1, "I"),
    ]
    result = []
    for value, symbol in pairs:
        while number >= value:
            result.append(symbol)
            number -= value
    return "".join(result)


def solve():
    path = Path(__file__).with_name("roman.txt")
    if not path.exists():
        raise FileNotFoundError("Place roman.txt in EulerProblems/")
    saved = 0
    for line in path.read_text().splitlines():
        value = to_int(line.strip())
        minimal = to_roman(value)
        saved += len(line.strip()) - len(minimal)
    return saved


if __name__ == "__main__":
    print(solve())
