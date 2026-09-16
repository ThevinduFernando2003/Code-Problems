#!/bin/python3

import math
import os
import random
import re
import sys
from collections import deque


#
# Complete the 'countStablePerformanceIntervals' function below.
#
# Count subarrays whose max - min <= `limit`.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY metrics
#  2. INTEGER limit
#

def countStablePerformanceIntervals(metrics, limit):
    n = len(metrics)
    min_q = deque()
    max_q = deque()
    left = 0
    total = 0
    for right, value in enumerate(metrics):
        while min_q and metrics[min_q[-1]] > value:
            min_q.pop()
        while max_q and metrics[max_q[-1]] < value:
            max_q.pop()
        min_q.append(right)
        max_q.append(right)
        while metrics[max_q[0]] - metrics[min_q[0]] > limit:
            if min_q[0] == left:
                min_q.popleft()
            if max_q[0] == left:
                max_q.popleft()
            left += 1
        total += right - left + 1
    return total


if __name__ == '__main__':
    metrics_count = int(input().strip())
    metrics = [int(input().strip()) for _ in range(metrics_count)]
    limit = int(input().strip())
    result = countStablePerformanceIntervals(metrics, limit)
    print(result)
