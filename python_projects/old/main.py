#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the maxRegion function below.


def maxRegion(grid):
    max_cell_counter = 0
    for row in range(len(grid)):
        for col in range(len(grid[0])):
            if grid[row][col] == 1:
                region_cell_count = count_region_cells(grid, row, col)
                max_cell_counter = max(max_cell_counter, region_cell_count)
    return max_cell_counter


def count_region_cells(grid, row, col):
    if any([row < 0, col < 0, row >= len(grid), col >= len(grid[0])]):
        return 0

    if grid[row][col] == 0:
        return 0

    cell_count = 0
    grid[row][col] = 0

    for r in range(row-1, row+2):
        for c in range(col-1, col+2):
            if any([r != row, c != col]):
                cell_count += count_region_cells(grid, r, c)

    return cell_count


if __name__ == '__main__':
    os.environ['OUTPUT_PATH'] = 'C:/dev/python'
    fptr = open(os.environ('OUTPUT_PATH'), 'w')

    n = int(input())

    m = int(input())

    grid = []

    for _ in range(n):
        grid.append(list(map(int, input().rstrip().split())))

        res = maxRegion(grid)

        fptr.write(str(res) + '\n')

        fptr.close()
