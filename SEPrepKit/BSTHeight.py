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

    is_child = [False] * n
    for i in range(n):
        if leftChild[i] != -1:
            is_child[leftChild[i]] = True
        if rightChild[i] != -1:
            is_child[rightChild[i]] = True

    root = next(i for i in range(n) if not is_child[i])

    def height(node):
        if node == -1:
            return 0
        return 1 + max(height(leftChild[node]), height(rightChild[node]))

    return height(root)

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
