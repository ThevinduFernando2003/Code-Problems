#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'zeroSumTripletsInWindow' function below.
#
# Unique value triplets (a, b, c) with a + b + c = 0 that appear as three
# distinct positions inside some contiguous window of length `window`.
# The function is expected to return a 2D_INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY arr
#  2. INTEGER window
#

def zeroSumTripletsInWindow(arr, window):
    n = len(arr)
    unique = set()
    for start in range(n):
        end = min(n, start + window)
        if end - start < 3:
            continue
        nums = sorted(arr[start:end])
        m = len(nums)
        for i in range(m - 2):
            lo, hi = i + 1, m - 1
            while lo < hi:
                total = nums[i] + nums[lo] + nums[hi]
                if total == 0:
                    unique.add((nums[i], nums[lo], nums[hi]))
                    lo += 1
                    hi -= 1
                elif total < 0:
                    lo += 1
                else:
                    hi -= 1
    return [list(triplet) for triplet in sorted(unique)]


if __name__ == '__main__':
    arr_count = int(input().strip())
    arr = [int(input().strip()) for _ in range(arr_count)]
    window = int(input().strip())
    result = zeroSumTripletsInWindow(arr, window)
    print(len(result))
    for triplet in result:
        print(' '.join(map(str, triplet)))
