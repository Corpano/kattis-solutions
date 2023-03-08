import sys
case = 1

for line in sys.stdin:
    min = float('infinity')
    max = -float('infinity')

    for numStr in line.split()[1::]:
        num = int(numStr)
        if num < min:
            min = num
        if num > max:
            max = num

    print("Case %i: %i %i %i"%(case, min, max, (max - min)))
    case = case + 1