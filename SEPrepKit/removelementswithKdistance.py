#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'debounceTimestamps' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY timestamps
#  2. INTEGER K
#

def debounceTimestamps(timestamps, K):
    if not timestamps:
        return 0

    write = 1

    for i in range(1, len(timestamps)):
        if timestamps[i] - timestamps[write - 1] >= K:
            timestamps[write] = timestamps[i]
            write += 1

    return write

if __name__ == '__main__':
    first_line = input().strip().split()
    n = int(first_line[0])
    k = int(first_line[1])

    timestamps = []
    if n > 0:
        timestamps = list(map(int, input().strip().split()))

    result = debounceTimestamps(timestamps, k)

    print(result)
