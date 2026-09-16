#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'maximizeVideoStreamRevenue' function below.
#
# 0/1 knapsack: each stream is [bandwidth, revenue].
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. 2D_INTEGER_ARRAY streams
#  2. INTEGER bandwidth
#

def maximizeVideoStreamRevenue(streams, bandwidth):
    dp = [0] * (bandwidth + 1)
    for cost, revenue in streams:
        for cap in range(bandwidth, cost - 1, -1):
            dp[cap] = max(dp[cap], dp[cap - cost] + revenue)
    return dp[bandwidth]


if __name__ == '__main__':
    streams_rows = int(input().strip())
    streams_columns = int(input().strip())
    streams = []
    for _ in range(streams_rows):
        streams.append(list(map(int, input().rstrip().split())))
    bandwidth = int(input().strip())
    result = maximizeVideoStreamRevenue(streams, bandwidth)
    print(result)
