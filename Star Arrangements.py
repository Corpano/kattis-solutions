import math

def check(firstRow, secondRow, n):
    sum = 0
    next = firstRow
    while True:
        sum += next
        next = secondRow if next == firstRow else firstRow;

        if sum == n:
            return True
        elif sum > n:
            return False

numOfStars = int(input())

print(str(numOfStars) + ":")
for first in range(2, math.ceil(numOfStars/2) + 1):
    for second in range(first-1, first+1):
        if check(first, second, numOfStars):
            print(str(first) + "," + str(second))