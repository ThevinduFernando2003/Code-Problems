#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'getBinarySearchTreeHeight' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY values
#  2. INTEGER_ARRAY leftChild
#  3. INTEGER_ARRAY rightChild
#

def getBinarySearchTreeHeight(values, leftChild, rightChild):
    n = len(values)
    if n == 0:
        return 0

    n = min(n, len(leftChild), len(rightChild))
    if n == 0:
        return 0

    is_child = [False] * n
    for i in range(n):
        left = leftChild[i]
        right = rightChild[i]
        if left != -1 and 0 <= left < n:
            is_child[left] = True
        if right != -1 and 0 <= right < n:
            is_child[right] = True

    root = 0
    for i in range(n):
        if not is_child[i]:
            root = i
            break

    stack = [(root, 1)]
    max_height = 0

    while stack:
        node, depth = stack.pop()

        if node < 0 or node >= n:
            continue

        max_height = max(max_height, depth)

        left = leftChild[node]
        right = rightChild[node]

        if left != -1 and 0 <= left < n:
            stack.append((left, depth + 1))
        if right != -1 and 0 <= right < n:
            stack.append((right, depth + 1))

    return max_height

if __name__ == '__main__':
    values_count = int(input().strip())

    values = []

    for _ in range(values_count):
        values_item = int(input().strip())
        values.append(values_item)

    leftChild_count = int(input().strip())

    leftChild = []

    for _ in range(leftChild_count):
        leftChild_item = int(input().strip())
        leftChild.append(leftChild_item)

    rightChild_count = int(input().strip())

    rightChild = []

    for _ in range(rightChild_count):
        rightChild_item = int(input().strip())
        rightChild.append(rightChild_item)

    result = getBinarySearchTreeHeight(values, leftChild, rightChild)

    print(result)
