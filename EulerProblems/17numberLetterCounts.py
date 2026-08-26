"""Project Euler Problem 17: Number Letter Counts"""

ONES = [
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
]

TENS = ["", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]


def under_thousand(n: int) -> str:
    if n == 0:
        return ""
    if n < 20:
        return ONES[n]
    if n < 100:
        tens, ones = divmod(n, 10)
        return TENS[tens] + (ONES[ones] if ones else "")
    hundreds, remainder = divmod(n, 100)
    text = ONES[hundreds] + "hundred"
    if remainder:
        text += under_thousand(remainder)
    return text


def in_words(n: int) -> str:
    if n == 0:
        return "zero"

    parts = []
    billions, n = divmod(n, 1_000_000_000)
    millions, n = divmod(n, 1_000_000)
    thousands, n = divmod(n, 1_000)

    if billions:
        parts.append(under_thousand(billions) + "billion")
    if millions:
        parts.append(under_thousand(millions) + "million")
    if thousands:
        parts.append(under_thousand(thousands) + "thousand")
    if n:
        parts.append(under_thousand(n))

    return "".join(parts)


def solve(limit: int = 1000) -> int:
    return sum(len(in_words(number)) for number in range(1, limit))


if __name__ == "__main__":
    print(solve())
