#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'countResponseTimeRegressions' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY responseTimes as parameter.
#

def countResponseTimeRegressions(responseTimes):
    # Write your code here
    if len(responseTimes) <= 1:
        return 0
    new_sum = 0
    count = 0
    for time in range(len(responseTimes)):
        current = responseTimes[time]
        if time > 0:
            pre_ave = new_sum / time
            if current > pre_ave:
                count+= 1
        new_sum += current
    return count
        

if __name__ == '__main__':
    responseTimes_count = int(input().strip())

    responseTimes = []

    for _ in range(responseTimes_count):
        responseTimes_item = int(input().strip())
        responseTimes.append(responseTimes_item)

    result = countResponseTimeRegressions(responseTimes)

    print(result)
