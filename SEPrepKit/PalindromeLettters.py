#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'isAlphabeticPalindrome' function below.
#
# The function is expected to return a BOOLEAN.
# The function accepts STRING code as parameter.
#

def isAlphabeticPalindrome(code):
    left = 0
    right = len(code) - 1

    while left < right:
        while left < right and not code[left].isalpha():
            left += 1
        while left < right and not code[right].isalpha():
            right -= 1

        if code[left].lower() != code[right].lower():
            return 0

        left += 1
        right -= 1

    return 1


if __name__ == '__main__':
    code = input().strip()
    result = isAlphabeticPalindrome(code)
    print(result)