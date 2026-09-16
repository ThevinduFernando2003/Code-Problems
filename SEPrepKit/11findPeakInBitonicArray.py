#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'findPeakInBitonicArray' function below.
#
# Peak index in a bitonic array (strictly increasing then strictly decreasing).
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def findPeakInBitonicArray(arr):
    left, right = 0, len(arr) - 1
    while left < right:
        mid = (left + right) // 2
        if arr[mid] < arr[mid + 1]:
            left = mid + 1
        else:
            right = mid
    return left


if __name__ == '__main__':
    arr_count = int(input().strip())
    arr = [int(input().strip()) for _ in range(arr_count)]
    result = findPeakInBitonicArray(arr)
    print(result)
