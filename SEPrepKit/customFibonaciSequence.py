#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'customFibonacciSequence' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER n as parameter.
#

def customFibonacciSequence(n):
    if n == 0:
        return 1
    if n == 1:
        return 2

    prev2 = 1
    prev1 = 2

    for _ in range(2, n + 1):
        current = prev1 + prev2
        prev2 = prev1
        prev1 = current

    return prev1

if __name__ == '__main__':
    n = int(input().strip())

    result = customFibonacciSequence(n)

    print(result)
