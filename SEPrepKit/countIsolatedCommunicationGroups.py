#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'countIsolatedCommunicationGroups' function below.
#
# Count connected components among n nodes given undirected links.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. 2D_INTEGER_ARRAY links
#  2. INTEGER n
#

def countIsolatedCommunicationGroups(links, n):
    parent = list(range(n))
    rank = [0] * n

    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x

    def union(a, b):
        ra, rb = find(a), find(b)
        if ra == rb:
            return
        if rank[ra] < rank[rb]:
            parent[ra] = rb
        elif rank[ra] > rank[rb]:
            parent[rb] = ra
        else:
            parent[rb] = ra
            rank[ra] += 1

    for u, v in links:
        union(u, v)

    return len({find(i) for i in range(n)})


if __name__ == '__main__':
    links_rows = int(input().strip())
    links_columns = int(input().strip())

    links = []

    for _ in range(links_rows):
        links.append(list(map(int, input().rstrip().split())))

    n = int(input().strip())

    result = countIsolatedCommunicationGroups(links, n)

    print(result)
