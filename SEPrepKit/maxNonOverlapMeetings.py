#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'maximizeNonOverlappingMeetings' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY meetings as parameter.
#

def maximizeNonOverlappingMeetings(meetings):
    if not meetings:
        return 0

    meetings.sort(key=lambda interval: interval[1])

    count = 0
    last_end = float("-inf")

    for start, end in meetings:
        if start >= last_end:
            count += 1
            last_end = end

    return count

if __name__ == '__main__':
    meetings_rows = int(input().strip())
    meetings_columns = int(input().strip())

    meetings = []

    for _ in range(meetings_rows):
        meetings.append(list(map(int, input().rstrip().split())))

    result = maximizeNonOverlappingMeetings(meetings)

    print(result)
