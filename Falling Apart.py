import heapq

n = int(input())

heapArr = []
for numStr in input().split():
    heapq.heappush(heapArr, int(numStr))

heapArr.sort(reverse=True)

alice = 0
bob = 0

lastTurnAlice = False
for num in heapArr:
    if lastTurnAlice:
        bob += num;
    else:
        alice += num;
    lastTurnAlice = not lastTurnAlice

print("%i %i" %(alice, bob))