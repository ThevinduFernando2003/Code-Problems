#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'processCouponStackOperations' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts STRING_ARRAY operations as parameter.
#

def processCouponStackOperations(operations):
    stack = []

    for operation in operations:
        if operation == "POP":
            stack.pop()
        elif operation == "DUP":
            stack.append(stack[-1])
        elif operation == "ADD":
            b = stack.pop()
            a = stack.pop()
            stack.append(a + b)
        elif operation == "SUB":
            b = stack.pop()
            a = stack.pop()
            stack.append(a - b)
        else:
            stack.append(int(operation))

    return stack

if __name__ == '__main__':
    operations_count = int(input().strip())

    operations = []

    for _ in range(operations_count):
        operations_item = input()
        operations.append(operations_item)

    result = processCouponStackOperations(operations)

    print('\n'.join(map(str, result)))
