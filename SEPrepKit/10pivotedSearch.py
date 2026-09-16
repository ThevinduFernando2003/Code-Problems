#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'pivotedSearch' function below.
#
# Search target in a rotated (pivoted) sorted array. Return index or -1.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY arr
#  2. INTEGER target
#

def pivotedSearch(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        if arr[left] <= arr[mid]:
            if arr[left] <= target < arr[mid]:
                right = mid - 1
            else:
                left = mid + 1
        else:
            if arr[mid] < target <= arr[right]:
                left = mid + 1
            else:
                right = mid - 1
    return -1


if __name__ == '__main__':
    arr_count = int(input().strip())
    arr = [int(input().strip()) for _ in range(arr_count)]
    target = int(input().strip())
    result = pivotedSearch(arr, target)
    print(result)
