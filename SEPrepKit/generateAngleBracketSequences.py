#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'generateAngleBracketSequences' function below.
#
# The function is expected to return a STRING_ARRAY.
# The function accepts INTEGER n as parameter.
#

def generateAngleBracketSequences(n):
    sequences = []

    def add_bracket(open_left, close_left, current):
        if open_left == 0 and close_left == 0:
            sequences.append(current)
            return
        if open_left > 0:
            add_bracket(open_left - 1, close_left, current + '<')
        if close_left > open_left:
            add_bracket(open_left, close_left - 1, current + '>')

    add_bracket(n, n, '')
    return sequences


if __name__ == '__main__':
    n = int(input().strip())

    result = generateAngleBracketSequences(n)

    print('\n'.join(result))
