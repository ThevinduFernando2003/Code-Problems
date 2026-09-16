#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'minCostConvertStringArrays' function below.
#
# Edit distance between two string arrays: insert/delete a word costs
# its length, replace costs Levenshtein distance of the two words.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. STRING_ARRAY source
#  2. STRING_ARRAY target
#

def _levenshtein(a, b):
    if a == b:
        return 0
    if not a:
        return len(b)
    if not b:
        return len(a)
    prev = list(range(len(b) + 1))
    for i, ca in enumerate(a, 1):
        curr = [i]
        for j, cb in enumerate(b, 1):
            ins = curr[j - 1] + 1
            delete = prev[j] + 1
            replace = prev[j - 1] + (ca != cb)
            curr.append(min(ins, delete, replace))
        prev = curr
    return prev[-1]


def minCostConvertStringArrays(source, target):
    n, m = len(source), len(target)
    inf = 10 ** 18
    dp = [[inf] * (m + 1) for _ in range(n + 1)]
    dp[0][0] = 0
    for i in range(n):
        dp[i + 1][0] = dp[i][0] + len(source[i])
    for j in range(m):
        dp[0][j + 1] = dp[0][j] + len(target[j])
    for i in range(n):
        for j in range(m):
            dp[i + 1][j + 1] = min(
                dp[i][j] + _levenshtein(source[i], target[j]),
                dp[i][j + 1] + len(source[i]),
                dp[i + 1][j] + len(target[j]),
            )
    return dp[n][m]


if __name__ == '__main__':
    source_count = int(input().strip())
    source = [input() for _ in range(source_count)]
    target_count = int(input().strip())
    target = [input() for _ in range(target_count)]
    result = minCostConvertStringArrays(source, target)
    print(result)
