#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'processTwoStackQueue' function below.
#
# Queries: 1 x enqueue, 2 dequeue, 3 print front.
# The function is expected to return an INTEGER_ARRAY of printed fronts.
# The function accepts STRING_ARRAY queries as parameter.
#

def processTwoStackQueue(queries):
    inbox, outbox = [], []
    printed = []

    def shift():
        if not outbox:
            while inbox:
                outbox.append(inbox.pop())

    for query in queries:
        parts = query.split()
        op = int(parts[0])
        if op == 1:
            inbox.append(int(parts[1]))
        elif op == 2:
            shift()
            if outbox:
                outbox.pop()
        else:
            shift()
            if outbox:
                printed.append(outbox[-1])
    return printed


if __name__ == '__main__':
    q = int(input().strip())
    queries = [input().rstrip() for _ in range(q)]
    result = processTwoStackQueue(queries)
    print('\n'.join(map(str, result)))
