#!/bin/python3

import math
import os
import random
import re
import sys
import heapq


#
# Complete the 'maxProfitTasksDeadlinesServers' function below.
#
# Unit-time jobs [deadline, profit] on `servers` identical machines.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. 2D_INTEGER_ARRAY tasks
#  2. INTEGER servers
#

def maxProfitTasksDeadlinesServers(tasks, servers):
    if not tasks or servers <= 0:
        return 0
    tasks = sorted(tasks, key=lambda task: task[0])
    chosen = []
    for deadline, profit in tasks:
        heapq.heappush(chosen, profit)
        capacity = deadline * servers
        if len(chosen) > capacity:
            heapq.heappop(chosen)
    return sum(chosen)


if __name__ == '__main__':
    tasks_rows = int(input().strip())
    tasks_columns = int(input().strip())
    tasks = [list(map(int, input().rstrip().split())) for _ in range(tasks_rows)]
    servers = int(input().strip())
    result = maxProfitTasksDeadlinesServers(tasks, servers)
    print(result)
