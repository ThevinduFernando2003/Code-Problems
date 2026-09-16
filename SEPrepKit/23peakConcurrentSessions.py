#!/bin/python3

import math
import os
import random
import re
import sys
from collections import defaultdict


#
# Complete the 'peakConcurrentSessionsPerGroup' function below.
#
# sessions[i] = [start, end, groupId]. Peak simultaneous open sessions
# for each group. Return peaks ordered by group id.
# The function is expected to return an INTEGER_ARRAY.
# The function accepts 2D_INTEGER_ARRAY sessions as parameter.
#

def peakConcurrentSessionsPerGroup(sessions):
    events = defaultdict(list)
    for start, end, group in sessions:
        events[group].append((start, 1))
        events[group].append((end, -1))
    peaks = []
    for group in sorted(events):
        timeline = events[group]
        timeline.sort(key=lambda e: (e[0], e[1]))
        current = peak = 0
        for _, delta in timeline:
            current += delta
            peak = max(peak, current)
        peaks.append(peak)
    return peaks


if __name__ == '__main__':
    sessions_rows = int(input().strip())
    sessions_columns = int(input().strip())
    sessions = []
    for _ in range(sessions_rows):
        sessions.append(list(map(int, input().rstrip().split())))
    result = peakConcurrentSessionsPerGroup(sessions)
    print('\n'.join(map(str, result)))
