#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'nextGreaterElementOffsets' function below.
#
# For each index, distance to the next strictly greater element, or 0 if none.
# The function is expected to return an INTEGER_ARRAY.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def nextGreaterElementOffsets(arr):
    n = len(arr)
    offsets = [0] * n
    stack = []
    for i, value in enumerate(arr):
        while stack and arr[stack[-1]] < value:
            j = stack.pop()
            offsets[j] = i - j
        stack.append(i)
    return offsets


if __name__ == '__main__':
    arr_count = int(input().strip())
    arr = [int(input().strip()) for _ in range(arr_count)]
    result = nextGreaterElementOffsets(arr)
    print('\n'.join(map(str, result)))
