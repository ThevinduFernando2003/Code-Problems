"""Project Euler Problem 19: Counting Sundays"""

from datetime import date


def solve(start_year: int = 1901, end_year: int = 2000) -> int:
    count = 0
    for year in range(start_year, end_year + 1):
        for month in range(1, 13):
            if date(year, month, 1).weekday() == 6:
                count += 1
    return count


if __name__ == "__main__":
    print(solve())
