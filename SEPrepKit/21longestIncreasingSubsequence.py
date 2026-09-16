#!/bin/python3

import math
import os
import random
import re
import sys
import bisect


#
# Complete the 'longestIncreasingSubsequenceLength' function below.
#
# Patience-sorting LIS length in O(n log n).
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def longestIncreasingSubsequenceLength(arr):
    tails = []
    for value in arr:
        pos = bisect.bisect_left(tails, value)
        if pos == len(tails):
            tails.append(value)
        else:
            tails[pos] = value
    return len(tails)


if __name__ == '__main__':
    arr_count = int(input().strip())
    arr = [int(input().strip()) for _ in range(arr_count)]
    result = longestIncreasingSubsequenceLength(arr)
    print(result)
