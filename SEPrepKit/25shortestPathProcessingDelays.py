#!/bin/python3

import math
import os
import random
import re
import sys
import heapq


#
# Complete the 'shortestPathWithProcessingDelays' function below.
#
# Undirected weighted graph. delays[i] is added when node i is visited.
# Edges are [u, v, w] with 0-based node ids. Return -1 if unreachable.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. INTEGER_ARRAY delays
#  3. 2D_INTEGER_ARRAY edges
#  4. INTEGER source
#  5. INTEGER target
#

def shortestPathWithProcessingDelays(n, delays, edges, source, target):
    graph = [[] for _ in range(n)]
    for u, v, w in edges:
        graph[u].append((v, w))
        graph[v].append((u, w))
    inf = 10 ** 30
    dist = [inf] * n
    dist[source] = delays[source] if delays else 0
    heap = [(dist[source], source)]
    while heap:
        time, node = heapq.heappop(heap)
        if time != dist[node]:
            continue
        if node == target:
            return time
        for nxt, weight in graph[node]:
            cand = time + weight + delays[nxt]
            if cand < dist[nxt]:
                dist[nxt] = cand
                heapq.heappush(heap, (cand, nxt))
    return -1


if __name__ == '__main__':
    n = int(input().strip())
    delays_count = int(input().strip())
    delays = [int(input().strip()) for _ in range(delays_count)]
    edges_rows = int(input().strip())
    edges_columns = int(input().strip())
    edges = [list(map(int, input().rstrip().split())) for _ in range(edges_rows)]
    source = int(input().strip())
    target = int(input().strip())
    result = shortestPathWithProcessingDelays(n, delays, edges, source, target)
    print(result)
