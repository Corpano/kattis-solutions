import sys
sys.setrecursionlimit(1000000000)
inp = list(input())

lastLetter = ''
letterPositions = {}

idx = 0;
while idx < len(inp):
    curr = inp[idx]
    if curr == lastLetter or curr == '\n':
        inp.pop(idx)
        idx -= 1
    else:
        if curr in letterPositions.keys():
            letterPositions[curr].append(idx)
        else:
            letterPositions[curr] = [idx]

    lastLetter = curr
    idx += 1


def recurse(i, start, first, seen:set) -> int:
    if i >= len(inp):
        return 0;

    total = 0
    if inp[i] == start and not first:
        return 0;
    elif inp[i] in seen:
        return recurse(i + 1, start, False, seen);
    else:
        seen.add(inp[i]);
        total += recurse(i + 1, start, False, seen)

    if not first:
        total += 1

    return total;

total = 0
for idx in range(len(inp)-1):
    r = recurse(idx, inp[idx], True, set([]))
    total += r

print(total)
