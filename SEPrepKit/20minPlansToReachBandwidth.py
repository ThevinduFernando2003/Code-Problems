#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'minPlansToReachBandwidth' function below.
#
# Unbounded knapsack / coin change: fewest plans whose bandwidths sum to target.
# Return -1 if impossible.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY plans
#  2. INTEGER target
#

def minPlansToReachBandwidth(plans, target):
    inf = target + 1
    dp = [0] + [inf] * target
    for amount in range(1, target + 1):
        for plan in plans:
            if plan <= amount:
                dp[amount] = min(dp[amount], dp[amount - plan] + 1)
    return dp[target] if dp[target] <= target else -1


if __name__ == '__main__':
    plans_count = int(input().strip())
    plans = [int(input().strip()) for _ in range(plans_count)]
    target = int(input().strip())
    result = minPlansToReachBandwidth(plans, target)
    print(result)
