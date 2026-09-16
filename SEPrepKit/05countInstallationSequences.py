#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'countInstallationSequences' function below.
#
# The function is expected to return a STRING.
# The function accepts INTEGER n as parameter.
#

def countInstallationSequences(n):
    if n < 0:
        return '0'
    if n <= 1:
        return '1'
    prev, curr = 1, 1
    for _ in range(2, n + 1):
        prev, curr = curr, prev + curr
    return str(curr)


if __name__ == '__main__':
    n = int(input().strip())
    result = countInstallationSequences(n)
    print(result)
