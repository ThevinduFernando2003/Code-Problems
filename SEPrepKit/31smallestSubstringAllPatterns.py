#!/bin/python3

import math
import os
import random
import re
import sys
from collections import defaultdict, deque


#
# Complete the 'smallestSubstringContainingAllPatterns' function below.
#
# Shortest substring of `text` that contains every pattern as a substring.
# Empty string if some pattern is missing.
# The function is expected to return a STRING.
# The function accepts following parameters:
#  1. STRING text
#  2. STRING_ARRAY patterns
#

def smallestSubstringContainingAllPatterns(text, patterns):
    needed = [p for p in patterns if p]
    if not needed:
        return ''
    events = []
    for pid, pattern in enumerate(needed):
        start = text.find(pattern)
        if start == -1:
            return ''
        while start != -1:
            events.append((start, start + len(pattern) - 1, pid))
            start = text.find(pattern, start + 1)
    events.sort()
    count = defaultdict(int)
    have = 0
    queue = deque()
    best_len = math.inf
    best = ''
    for start, end, pid in events:
        queue.append((start, end, pid))
        if count[pid] == 0:
            have += 1
        count[pid] += 1
        while queue and have == len(needed):
            left, _, left_pid = queue[0]
            window_end = max(item[1] for item in queue)
            length = window_end - left + 1
            if length < best_len:
                best_len = length
                best = text[left:window_end + 1]
            queue.popleft()
            count[left_pid] -= 1
            if count[left_pid] == 0:
                have -= 1
    return best


if __name__ == '__main__':
    text = input()
    patterns_count = int(input().strip())
    patterns = [input() for _ in range(patterns_count)]
    result = smallestSubstringContainingAllPatterns(text, patterns)
    print(result)
