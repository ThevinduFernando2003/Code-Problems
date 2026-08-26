"""Project Euler Problem 54: Poker Hands"""

from collections import Counter
from itertools import combinations
from pathlib import Path

RANKS = "23456789TJQKA"


def hand_value(cards):
    values = sorted([RANKS.index(card[0]) for card in cards], reverse=True)
    suits = [card[1] for card in cards]
    counts = sorted(Counter(values).values(), reverse=True)
    order = sorted(Counter(values).keys(), reverse=True, key=lambda v: (Counter(values)[v], v))
    flush = len(set(suits)) == 1
    straight = values == list(range(values[0], values[0] - 5, -1)) or values == [12, 3, 2, 1, 0]
    if straight and flush:
        return (8, values)
    if counts[0] == 4:
        return (7, order)
    if counts == [3, 2]:
        return (6, order)
    if flush:
        return (5, values)
    if straight:
        return (4, [values[0]])
    if counts[0] == 3:
        return (3, order)
    if counts == [2, 2, 1]:
        pairs = sorted([v for v in order if Counter(values)[v] == 2], reverse=True)
        kicker = [v for v in order if Counter(values)[v] == 1][0]
        return (2, pairs + [kicker])
    if counts[0] == 2:
        return (1, order)
    return (0, values)


def solve():
    path = Path(__file__).with_name("poker.txt")
    if not path.exists():
        raise FileNotFoundError("Place poker.txt in EulerProblems/")
    wins = 0
    for line in path.read_text().splitlines():
        cards = line.split()
        p1 = [cards[i] + cards[i + 1] for i in range(0, 10, 2)]
        p2 = [cards[i] + cards[i + 1] for i in range(10, 20, 2)]
        wins += hand_value(p1) > hand_value(p2)
    return wins


if __name__ == "__main__":
    print(solve())
