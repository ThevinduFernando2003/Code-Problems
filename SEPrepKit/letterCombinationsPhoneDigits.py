#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'minTasksToCancelForNoConflict' function below.
#
# Lexicographical letter combinations of a phone keypad string.
# The function is expected to return a STRING_ARRAY.
# The function accepts STRING digits as parameter.
#

KEYPAD = {
    '0': ['0'],
    '1': ['1'],
    '2': ['a', 'b', 'c'],
    '3': ['d', 'e', 'f'],
    '4': ['g', 'h', 'i'],
    '5': ['j', 'k', 'l'],
    '6': ['m', 'n', 'o'],
    '7': ['p', 'q', 'r', 's'],
    '8': ['t', 'u', 'v'],
    '9': ['w', 'x', 'y', 'z'],
}


def minTasksToCancelForNoConflict(digits):
    if not digits:
        return []

    combinations = []

    def dfs(index, current):
        if index == len(digits):
            combinations.append(current)
            return
        for letter in KEYPAD[digits[index]]:
            dfs(index + 1, current + letter)

    dfs(0, '')
    return combinations


if __name__ == '__main__':
    digits = input()

    result = minTasksToCancelForNoConflict(digits)

    print('\n'.join(result))
