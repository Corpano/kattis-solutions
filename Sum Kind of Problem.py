numSets = int(input())

for i in range(numSets):
    dataSetNum, upLim = input().split()
    evenSum = sum(range(2, int(upLim) * 2 + 2, 2))
    oddSum = sum(range(1, int(upLim) * 2 + 1, 2))
    totalSum = sum(range(1, int(upLim) + 1, 1))
    print(dataSetNum, totalSum, oddSum, evenSum)
