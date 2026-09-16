#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'indexCombinationsWithTargetWeight' function below.
#
# All combinations of distinct indices whose weights sum to target.
# Each combination is sorted; the list of combinations is lexicographical.
# The function is expected to return a 2D_INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY weights
#  2. INTEGER target
#

def indexCombinationsWithTargetWeight(weights, target):
    n = len(weights)
    combinations = []

    def dfs(start, remaining, path):
        if remaining == 0:
            combinations.append(path[:])
            return
        if remaining < 0:
            return
        for i in range(start, n):
            if weights[i] > remaining:
                continue
            path.append(i)
            dfs(i + 1, remaining - weights[i], path)
            path.pop()

    dfs(0, target, [])
    return combinations


if __name__ == '__main__':
    weights_count = int(input().strip())
    weights = [int(input().strip()) for _ in range(weights_count)]
    target = int(input().strip())
    result = indexCombinationsWithTargetWeight(weights, target)
    print(len(result))
    for combo in result:
        print(' '.join(map(str, combo)))
