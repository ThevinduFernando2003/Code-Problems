#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'canPlaceSecurityCameras' function below.
#
# The function is expected to return a BOOLEAN.
# The function accepts following parameters:
#  1. INTEGER N
#  2. 2D_INTEGER_ARRAY grid
#

def canPlaceSecurityCameras(N, grid):
    size = len(grid)
    if N > size:
        return False
    used_columns = set()
    used_diagonals = set()
    used_anti_diagonals = set()

    def place(row, placed):
        if placed == N:
            return True
        if row == size or size - row < N - placed:
            return False
        if place(row + 1, placed):
            return True
        for col in range(size):
            if (
                grid[row][col] == 1
                or col in used_columns
                or (row + col) in used_diagonals
                or (row - col) in used_anti_diagonals
            ):
                continue
            used_columns.add(col)
            used_diagonals.add(row + col)
            used_anti_diagonals.add(row - col)
            if place(row + 1, placed + 1):
                return True
            used_columns.remove(col)
            used_diagonals.remove(row + col)
            used_anti_diagonals.remove(row - col)
        return False

    return place(0, 0)


if __name__ == '__main__':
    N = int(input().strip())
    grid_rows = int(input().strip())
    grid_columns = int(input().strip())
    grid = []
    for _ in range(grid_rows):
        grid.append(list(map(int, input().rstrip().split())))
    result = canPlaceSecurityCameras(N, grid)
    print(int(result))
