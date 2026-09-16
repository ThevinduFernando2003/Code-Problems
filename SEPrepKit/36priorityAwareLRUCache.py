#!/bin/python3

import math
import os
import random
import re
import sys
from collections import OrderedDict, defaultdict


#
# Complete the 'processPriorityAwareLRU' function below.
#
# Cache operations on a priority-aware LRU:
#   PUT key value priority
#   GET key
# Evict lowest priority first, then the least recently used key at that
# priority. GET returns -1 on a miss. PUT replies are omitted.
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER capacity
#  2. STRING_ARRAY operations
#

def processPriorityAwareLRU(capacity, operations):
    data = {}
    buckets = defaultdict(OrderedDict)
    results = []

    def evict():
        if not buckets:
            return
        priority = min(buckets)
        key, _ = buckets[priority].popitem(last=False)
        if not buckets[priority]:
            del buckets[priority]
        del data[key]

    for operation in operations:
        parts = operation.split()
        op = parts[0].upper()
        if op.startswith('G'):
            key = int(parts[1]) if parts[1].lstrip('-').isdigit() else parts[1]
            if key not in data:
                results.append(-1)
                continue
            value, priority = data[key]
            buckets[priority].move_to_end(key)
            results.append(value)
        else:
            key = int(parts[1]) if parts[1].lstrip('-').isdigit() else parts[1]
            value = int(parts[2])
            priority = int(parts[3])
            if key in data:
                old_priority = data[key][1]
                del buckets[old_priority][key]
                if not buckets[old_priority]:
                    del buckets[old_priority]
                data[key] = (value, priority)
                buckets[priority][key] = True
                buckets[priority].move_to_end(key)
                continue
            if capacity <= 0:
                continue
            if len(data) >= capacity:
                evict()
            data[key] = (value, priority)
            buckets[priority][key] = True
    return results


if __name__ == '__main__':
    capacity = int(input().strip())
    operations_count = int(input().strip())
    operations = [input().rstrip() for _ in range(operations_count)]
    result = processPriorityAwareLRU(capacity, operations)
    print('\n'.join(map(str, result)))
