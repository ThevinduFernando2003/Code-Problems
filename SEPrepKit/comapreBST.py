#!/bin/python3

import math
import os
import random
import re
import sys
from collections import deque


NULL = 100001


class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


#
# Complete the 'verifySameMultisetDifferentStructure' function below.
#
# The function is expected to return a BOOLEAN.
# The function accepts following parameters:
#  1. INTEGER_ARRAY root1
#  2. INTEGER_ARRAY root2
#

def build_tree(values):
    if not values or values[0] == NULL:
        return None

    root = TreeNode(values[0])
    queue = deque([root])
    index = 1

    while queue and index < len(values):
        node = queue.popleft()

        if index < len(values):
            if values[index] != NULL:
                node.left = TreeNode(values[index])
                queue.append(node.left)
            index += 1

        if index < len(values):
            if values[index] != NULL:
                node.right = TreeNode(values[index])
                queue.append(node.right)
            index += 1

    return root


def get_values(values):
    return sorted(value for value in values if value != NULL)


def has_same_structure(root1, root2):
    stack = [(root1, root2)]

    while stack:
        node1, node2 = stack.pop()

        if node1 is None and node2 is None:
            continue
        if node1 is None or node2 is None:
            return False

        stack.append((node1.left, node2.left))
        stack.append((node1.right, node2.right))

    return True


def verifySameMultisetDifferentStructure(root1, root2):
    if get_values(root1) != get_values(root2):
        return False

    tree1 = build_tree(root1)
    tree2 = build_tree(root2)

    return not has_same_structure(tree1, tree2)


if __name__ == '__main__':
    root1_count = int(input().strip())

    root1 = []

    for _ in range(root1_count):
        root1_item = int(input().strip())
        root1.append(root1_item)

    root2_count = int(input().strip())

    root2 = []

    for _ in range(root2_count):
        root2_item = int(input().strip())
        root2.append(root2_item)

    result = verifySameMultisetDifferentStructure(root1, root2)

    print(int(result))
