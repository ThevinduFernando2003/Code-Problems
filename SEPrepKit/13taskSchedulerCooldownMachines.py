#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter, deque
import heapq


#
# Complete the 'minTimeToScheduleTasks' function below.
#
# Schedule tasks with a cooldown between repeats, using `machines`
# parallel workers each time unit.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY tasks
#  2. INTEGER cooldown
#  3. INTEGER machines
#

def minTimeToScheduleTasks(tasks, cooldown, machines):
    if not tasks:
        return 0
    machines = max(1, machines)
    heap = [-count for count in Counter(tasks).values()]
    heapq.heapify(heap)
    cooling = deque()
    time = 0
    while heap or cooling:
        time += 1
        while cooling and cooling[0][0] == time:
            heapq.heappush(heap, cooling.popleft()[1])
        launched = []
        for _ in range(machines):
            if not heap:
                break
            remaining = heapq.heappop(heap) + 1
            if remaining < 0:
                launched.append(remaining)
        for remaining in launched:
            cooling.append((time + cooldown + 1, remaining))
        if not heap and cooling:
            time = cooling[0][0] - 1
    return time


if __name__ == '__main__':
    tasks_count = int(input().strip())
    tasks = [int(input().strip()) for _ in range(tasks_count)]
    cooldown = int(input().strip())
    machines = int(input().strip())
    result = minTimeToScheduleTasks(tasks, cooldown, machines)
    print(result)
