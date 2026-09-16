#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'mergeHighDefinitionIntervals' function below.
#
# The function is expected to return a 2D_INTEGER_ARRAY.
# The function accepts 2D_INTEGER_ARRAY intervals as parameter.
#

def mergeHighDefinitionIntervals(intervals):
    if not intervals:
        return intervals
    intervals.sort(key=lambda interval: interval[0])
    merged = [intervals[0][:]]
    for start, end in intervals[1:]:
        if start <= merged[-1][1]:
            merged[-1][1] = max(merged[-1][1], end)
        else:
            merged.append([start, end])
    return merged


if __name__ == '__main__':
    intervals_rows = int(input().strip())
    intervals_columns = int(input().strip())
    intervals = []
    for _ in range(intervals_rows):
        intervals.append(list(map(int, input().rstrip().split())))
    result = mergeHighDefinitionIntervals(intervals)
    print('\n'.join([' '.join(map(str, x)) for x in result]))
