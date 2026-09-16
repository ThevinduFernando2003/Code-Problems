#!/bin/python3

import math
import os
import random
import re
import sys
from collections import defaultdict


#
# Complete the 'longestArithmeticSubsequence' function below.
#
# Longest subsequence with a fixed difference.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY arr
#  2. INTEGER difference
#

def longestArithmeticSubsequence(arr, difference):
    best = 0
    ending = defaultdict(int)
    for value in arr:
        length = ending[value - difference] + 1
        ending[value] = max(ending[value], length)
        best = max(best, ending[value])
    return best


if __name__ == '__main__':
    arr_count = int(input().strip())
    arr = [int(input().strip()) for _ in range(arr_count)]
    difference = int(input().strip())
    result = longestArithmeticSubsequence(arr, difference)
    print(result)
