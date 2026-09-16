#!/bin/python3

import math
import os
import random
import re
import sys
from collections import defaultdict


#
# Complete the 'countSubarraysWithSumAndBoundedMax' function below.
#
# Subarrays whose sum equals `target` and whose maximum is <= `limit`.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY arr
#  2. INTEGER target
#  3. INTEGER limit
#

def countSubarraysWithSumAndBoundedMax(arr, target, limit):
    def count_with_sum(segment):
        prefix = 0
        freq = defaultdict(int)
        freq[0] = 1
        total = 0
        for value in segment:
            prefix += value
            total += freq[prefix - target]
            freq[prefix] += 1
        return total

    total = 0
    segment = []
    for value in arr:
        if value > limit:
            total += count_with_sum(segment)
            segment = []
        else:
            segment.append(value)
    total += count_with_sum(segment)
    return total


if __name__ == '__main__':
    arr_count = int(input().strip())
    arr = [int(input().strip()) for _ in range(arr_count)]
    target = int(input().strip())
    limit = int(input().strip())
    result = countSubarraysWithSumAndBoundedMax(arr, target, limit)
    print(result)
