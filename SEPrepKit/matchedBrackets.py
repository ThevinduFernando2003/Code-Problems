#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'areBracketsProperlyMatched' function below.
#
# The function is expected to return a BOOLEAN.
# The function accepts STRING code_snippet as parameter.
#

def areBracketsProperlyMatched(code_snippet):
    stack = []

    for char in code_snippet:
        if char == '(':
            stack.append(char)
        elif char == ')':
            if not stack:
                return False
            stack.pop()

    return len(stack) == 0


def areDifferentBracketsProperlyMatched(code_snippet):
    pairs = {')': '(', ']': '[', '}': '{'}
    stack = []

    for char in code_snippet:
        if char in pairs.values():
            stack.append(char)
        elif char in pairs:
            if not stack or stack[-1] != pairs[char]:
                return False
            stack.pop()

    return len(stack) == 0


if __name__ == '__main__':
    code_snippet = input()

    result = areBracketsProperlyMatched(code_snippet)

    print(int(result))
