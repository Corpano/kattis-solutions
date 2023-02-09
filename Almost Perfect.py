import math
import sys
def getOutput(n):
    numbers = []
    sum = 0

    for i in range(1, int(math.sqrt(n) + 1)):
        if n % i == 0:
            if not numbers.count(i):
                numbers.append(i)
                sum += i
            if not numbers.count(n / i) and i != 1:
                numbers.append(n / i)
                sum += n / i

    if sum == n:
        return "perfect"
    elif sum >= n-2 and sum <= n+2:
        return "almost perfect"
    else:
        return "not perfect"

for i in sys.stdin:
    print(str(int(i)) + " " + getOutput(int(i)))