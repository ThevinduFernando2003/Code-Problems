#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'minTaskCancellationsToAvoidOverlaps' function below.
#
# Minimum intervals to drop so the rest are pairwise non-overlapping.
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY tasks as parameter.
#

def minTaskCancellationsToAvoidOverlaps(tasks):
    if not tasks:
        return 0
    tasks = sorted(tasks, key=lambda task: task[1])
    kept = 0
    last_end = float('-inf')
    for start, end in tasks:
        if start >= last_end:
            kept += 1
            last_end = end
    return len(tasks) - kept


if __name__ == '__main__':
    tasks_rows = int(input().strip())
    tasks_columns = int(input().strip())
    tasks = [list(map(int, input().rstrip().split())) for _ in range(tasks_rows)]
    result = minTaskCancellationsToAvoidOverlaps(tasks)
    print(result)
