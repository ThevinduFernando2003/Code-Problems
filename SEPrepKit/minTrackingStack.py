#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'processCouponStackOperations' function below.
#
# Min-tracking stack: push x / pop / top / getMin.
# The function is expected to return an INTEGER_ARRAY.
# The function accepts STRING_ARRAY operations as parameter.
#

def processCouponStackOperations(operations):
    result = []
    stack = []
    min_stack = []

    for operation in operations:
        if operation.startswith('pu'):
            value = int(operation.split()[1])
            stack.append(value)
            if not min_stack or value <= min_stack[-1]:
                min_stack.append(value)
        elif operation.startswith('po'):
            value = stack.pop()
            if min_stack and value == min_stack[-1]:
                min_stack.pop()
        elif operation.startswith('to'):
            result.append(stack[-1])
        elif operation.startswith('g'):
            result.append(min_stack[-1])

    return result


if __name__ == '__main__':
    operations_count = int(input().strip())

    operations = []

    for _ in range(operations_count):
        operations.append(input())

    result = processCouponStackOperations(operations)

    print('\n'.join(map(str, result)))
