#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'detectCycleInModuleDependency' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. 2D_INTEGER_ARRAY dependencies
#

def detectCycleInModuleDependency(n, dependencies):
    graph = [[] for _ in range(n)]
    indegree = [0] * n

    for u, v in dependencies:
        if u == v:
            return 1
        graph[u].append(v)
        indegree[v] += 1

    queue = [node for node in range(n) if indegree[node] == 0]
    processed = 0

    while queue:
        node = queue.pop()
        processed += 1

        for neighbor in graph[node]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                queue.append(neighbor)

    return 1 if processed < n else 0

if __name__ == '__main__':
    n = int(input().strip())

    dependencies_rows = int(input().strip())
    dependencies_columns = int(input().strip())

    dependencies = []

    for _ in range(dependencies_rows):
        dependencies.append(list(map(int, input().rstrip().split())))

    result = detectCycleInModuleDependency(n, dependencies)

    print(result)
