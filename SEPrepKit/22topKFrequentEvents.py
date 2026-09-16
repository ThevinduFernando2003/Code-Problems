#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter


#
# Complete the 'topKFrequentEventsPreserveOrder' function below.
#
# Return the k most frequent events. Ties keep first-seen order.
# The function is expected to return a STRING_ARRAY.
# The function accepts following parameters:
#  1. STRING_ARRAY events
#  2. INTEGER k
#

def topKFrequentEventsPreserveOrder(events, k):
    freq = Counter(events)
    first_index = {}
    for i, event in enumerate(events):
        if event not in first_index:
            first_index[event] = i
    unique = list(dict.fromkeys(events))
    unique.sort(key=lambda e: (-freq[e], first_index[e]))
    return unique[:k]


if __name__ == '__main__':
    events_count = int(input().strip())
    events = [input() for _ in range(events_count)]
    k = int(input().strip())
    result = topKFrequentEventsPreserveOrder(events, k)
    print('\n'.join(result))
