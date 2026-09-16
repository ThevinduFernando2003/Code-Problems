#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'minSpanningTreeWithOneFreeEdge' function below.
#
# MST cost after setting one edge's weight to 0. Nodes are 1-based.
# Return -1 if the graph is disconnected.
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER n
#  2. 2D_INTEGER_ARRAY edges
#

def minSpanningTreeWithOneFreeEdge(n, edges):
    parent = list(range(n + 1))
    rank = [0] * (n + 1)

    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x

    def union(a, b):
        a, b = find(a), find(b)
        if a == b:
            return False
        if rank[a] < rank[b]:
            a, b = b, a
        parent[b] = a
        if rank[a] == rank[b]:
            rank[a] += 1
        return True

    ordered = sorted(edges, key=lambda e: e[2])
    mst_weight = 0
    mst_edges = []
    for u, v, w in ordered:
        if union(u, v):
            mst_weight += w
            mst_edges.append((u, v, w))
    if len(mst_edges) != n - 1:
        return -1
    heaviest = max(w for _, _, w in mst_edges)
    return mst_weight - heaviest


if __name__ == '__main__':
    n = int(input().strip())
    edges_rows = int(input().strip())
    edges_columns = int(input().strip())
    edges = [list(map(int, input().rstrip().split())) for _ in range(edges_rows)]
    result = minSpanningTreeWithOneFreeEdge(n, edges)
    print(result)
