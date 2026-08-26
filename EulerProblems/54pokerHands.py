"""Project Euler Problem 54: Poker Hands"""

from collections import Counter
from pathlib import Path

RANKS = "23456789TJQKA"


def hand_value(cards: list[str]):
    values = sorted((RANKS.index(card[0]) for card in cards), reverse=True)
    suits = [card[1] for card in cards]
    counts = Counter(values)
    ordered = sorted(counts.keys(), key=lambda value: (counts[value], value), reverse=True)
    frequencies = sorted(counts.values(), reverse=True)
    is_flush = len(set(suits)) == 1
    is_straight = values == list(range(values[0], values[0] - 5, -1)) or values == [12, 3, 2, 1, 0]

    if is_straight and is_flush:
        return (8, values)
    if frequencies[0] == 4:
        return (7, ordered)
    if frequencies == [3, 2]:
        return (6, ordered)
    if is_flush:
        return (5, values)
    if is_straight:
        return (4, values)
    if frequencies[0] == 3:
        return (3, ordered)
    if frequencies == [2, 2, 1]:
        return (2, ordered)
    if frequencies[0] == 2:
        return (1, ordered)
    return (0, values)


def solve() -> int:
    path = Path(__file__).with_name("poker.txt")
    if not path.exists():
        raise FileNotFoundError("Download poker.txt from Project Euler and place it in EulerProblems/")

    wins = 0
    for line in path.read_text().splitlines():
        cards = line.split()
        if len(cards) < 10:
            continue
        if hand_value(cards[:5]) > hand_value(cards[5:]):
            wins += 1
    return wins


if __name__ == "__main__":
    print(solve())
