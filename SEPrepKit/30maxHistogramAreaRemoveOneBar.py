#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'maxHistogramAreaAfterRemovingOneBar' function below.
#
# Largest rectangle area in the histogram after deleting exactly one bar
# (the remaining bars close the gap).
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY heights as parameter.
#

def _largest_rectangle(heights):
    stack = []
    best = 0
    for i, height in enumerate(heights + [0]):
        while stack and heights[stack[-1]] > height:
            h = heights[stack.pop()]
            left = stack[-1] if stack else -1
            best = max(best, h * (i - left - 1))
        stack.append(i)
    return best


def maxHistogramAreaAfterRemovingOneBar(heights):
    n = len(heights)
    if n <= 1:
        return 0
    best = 0
    for i in range(n):
        remaining = heights[:i] + heights[i + 1:]
        best = max(best, _largest_rectangle(remaining))
    return best


if __name__ == '__main__':
    heights_count = int(input().strip())
    heights = [int(input().strip()) for _ in range(heights_count)]
    result = maxHistogramAreaAfterRemovingOneBar(heights)
    print(result)
