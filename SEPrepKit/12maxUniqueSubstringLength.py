#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'maxUniqueSubstringLength' function below.
#
# Longest substring of a session log with all unique characters.
# The function is expected to return an INTEGER.
# The function accepts STRING session as parameter.
#

def maxUniqueSubstringLength(session):
    last = {}
    start = 0
    best = 0
    for i, ch in enumerate(session):
        if ch in last and last[ch] >= start:
            start = last[ch] + 1
        last[ch] = i
        best = max(best, i - start + 1)
    return best


if __name__ == '__main__':
    session = input()
    result = maxUniqueSubstringLength(session)
    print(result)
