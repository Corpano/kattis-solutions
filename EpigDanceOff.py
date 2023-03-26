import sys
sys.setrecursionlimit(1000000)

first_line = input()
n,m = int(first_line.split()[0]), int(first_line.split()[1])

grid = []

for i in range(n):
    line = input()
    grid.append(list(line))

count = 1
for x in range(m):
    found = True
    for y in range(n):
        if grid[y][x] != '_':
            break;
        elif y == n-1:
            count += 1;

print(count)
