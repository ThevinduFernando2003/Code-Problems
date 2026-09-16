#!/bin/python3

import math
import os
import random
import re
import sys


#
# Complete the 'solveDiagonalSudoku' function below.
#
# 9x9 Sudoku with unique 3x3 blocks and both main diagonals unique.
# Empty cells are 0. Mutates and returns the solved board.
# The function is expected to return a 2D_INTEGER_ARRAY.
# The function accepts 2D_INTEGER_ARRAY board as parameter.
#

def solveDiagonalSudoku(board):
    rows = [set() for _ in range(9)]
    cols = [set() for _ in range(9)]
    boxes = [set() for _ in range(9)]
    diag = set()
    anti = set()
    empty = []

    def box_id(r, c):
        return (r // 3) * 3 + c // 3

    for r in range(9):
        for c in range(9):
            value = board[r][c]
            if value == 0:
                empty.append((r, c))
                continue
            rows[r].add(value)
            cols[c].add(value)
            boxes[box_id(r, c)].add(value)
            if r == c:
                diag.add(value)
            if r + c == 8:
                anti.add(value)

    def candidates(r, c):
        used = rows[r] | cols[c] | boxes[box_id(r, c)]
        if r == c:
            used |= diag
        if r + c == 8:
            used |= anti
        return [d for d in range(1, 10) if d not in used]

    def dfs():
        if not empty:
            return True
        idx = min(range(len(empty)), key=lambda i: len(candidates(*empty[i])))
        r, c = empty.pop(idx)
        for digit in candidates(r, c):
            board[r][c] = digit
            rows[r].add(digit)
            cols[c].add(digit)
            boxes[box_id(r, c)].add(digit)
            if r == c:
                diag.add(digit)
            if r + c == 8:
                anti.add(digit)
            if dfs():
                return True
            board[r][c] = 0
            rows[r].remove(digit)
            cols[c].remove(digit)
            boxes[box_id(r, c)].remove(digit)
            if r == c:
                diag.remove(digit)
            if r + c == 8:
                anti.remove(digit)
        empty.insert(idx, (r, c))
        return False

    dfs()
    return board


if __name__ == '__main__':
    board = [list(map(int, input().rstrip().split())) for _ in range(9)]
    result = solveDiagonalSudoku(board)
    print('\n'.join(' '.join(map(str, row)) for row in result))
