#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'medianOfTwoCircularlySortedLogs' function below.
#
# Each log is a rotated (circularly shifted) sorted array. Return the
# median of the combined multiset. For an even count, average the two
# middle values.
# The function is expected to return a FLOAT.
# The function accepts following parameters:
#  1. INTEGER_ARRAY log1
#  2. INTEGER_ARRAY log2
#

def _unrotate(arr):
    n = len(arr)
    if n <= 1:
        return arr[:]
    lo, hi = 0, n - 1
    while lo < hi:
        mid = (lo + hi) // 2
        if arr[mid] > arr[hi]:
            lo = mid + 1
        else:
            hi = mid
    pivot = lo
    return arr[pivot:] + arr[:pivot]


def _kth(a, b, k):
    if len(a) > len(b):
        return _kth(b, a, k)
    if not a:
        return b[k]
    if k == 0:
        return min(a[0], b[0])
    i = min(len(a), (k + 1) // 2)
    j = k + 1 - i
    if a[i - 1] < b[j - 1]:
        return _kth(a[i:], b, k - i)
    return _kth(a, b[j:], k - j)


def medianOfTwoCircularlySortedLogs(log1, log2):
    a = _unrotate(log1)
    b = _unrotate(log2)
    total = len(a) + len(b)
    if total == 0:
        return 0.0
    if total % 2:
        return float(_kth(a, b, total // 2))
    return (_kth(a, b, total // 2 - 1) + _kth(a, b, total // 2)) / 2.0


if __name__ == '__main__':
    log1_count = int(input().strip())
    log1 = [int(input().strip()) for _ in range(log1_count)]
    log2_count = int(input().strip())
    log2 = [int(input().strip()) for _ in range(log2_count)]
    result = medianOfTwoCircularlySortedLogs(log1, log2)
    print(result)
