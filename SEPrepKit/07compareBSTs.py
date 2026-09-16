#!/bin/python3

import math
import os
import random
import re
import sys
from collections import Counter, deque


NULL_MARKERS = {100001, -1}


class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


#
# Complete the 'verifySameMultisetDifferentStructure' function below.
#
# Same node values (as a multiset) but a different tree shape.
# Level-order arrays; 100001 and -1 are null.
#
# The function is expected to return a BOOLEAN.
# The function accepts following parameters:
#  1. INTEGER_ARRAY root1
#  2. INTEGER_ARRAY root2
#

def build_tree(values):
    if not values or values[0] in NULL_MARKERS:
        return None
    root = TreeNode(values[0])
    queue = deque([root])
    index = 1
    while queue and index < len(values):
        node = queue.popleft()
        if index < len(values):
            if values[index] not in NULL_MARKERS:
                node.left = TreeNode(values[index])
                queue.append(node.left)
            index += 1
        if index < len(values):
            if values[index] not in NULL_MARKERS:
                node.right = TreeNode(values[index])
                queue.append(node.right)
            index += 1
    return root


def value_multiset(root):
    counts = Counter()
    stack = [root]
    while stack:
        node = stack.pop()
        if node is None:
            continue
        counts[node.value] += 1
        stack.append(node.left)
        stack.append(node.right)
    return counts


def same_structure(root1, root2):
    stack = [(root1, root2)]
    while stack:
        a, b = stack.pop()
        if a is None and b is None:
            continue
        if a is None or b is None:
            return False
        stack.append((a.left, b.left))
        stack.append((a.right, b.right))
    return True


def verifySameMultisetDifferentStructure(root1, root2):
    tree1 = build_tree(root1)
    tree2 = build_tree(root2)
    if value_multiset(tree1) != value_multiset(tree2):
        return False
    return not same_structure(tree1, tree2)


if __name__ == '__main__':
    root1_count = int(input().strip())
    root1 = [int(input().strip()) for _ in range(root1_count)]
    root2_count = int(input().strip())
    root2 = [int(input().strip()) for _ in range(root2_count)]
    result = verifySameMultisetDifferentStructure(root1, root2)
    print(int(result))
