#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'longestAlternatingBinaryWithFlips' function below.
#
# Longest substring that can become alternating 01.. or 10.. using at most
# `flips` bit changes.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING binary
#  2. INTEGER flips
#

def longestAlternatingBinaryWithFlips(binary, flips):
    n = len(binary)
    best = 0
    for pattern in (0, 1):
        mismatches = 0
        left = 0
        for right, ch in enumerate(binary):
            expected = (pattern + right) % 2
            if int(ch) != expected:
                mismatches += 1
            while mismatches > flips:
                expected_left = (pattern + left) % 2
                if int(binary[left]) != expected_left:
                    mismatches -= 1
                left += 1
            best = max(best, right - left + 1)
    return best


if __name__ == '__main__':
    binary = input().strip()
    flips = int(input().strip())
    result = longestAlternatingBinaryWithFlips(binary, flips)
    print(result)
