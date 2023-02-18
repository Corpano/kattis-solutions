import heapq
from dataclasses import dataclass, field
from typing import Any


class Knight:
    year = 0
    strength = 0
    isKarl = False
    competeStrength = False

    def __init__(self, yr, str, isKarl):
        self.year = yr
        self.strength = str
        self.isKarl = isKarl

    def __lt__(self, other):
        if self.competeStrength:
            return self.strength > other.strength
        else:
            return self.year < other.year


firstLine = input()
k, n = int(firstLine.split()[0]), int(firstLine.split()[1])

knights = []

for i in range(n + k - 2 + 1):
    inp = input()
    knight = Knight(int(inp.split()[0]), int(inp.split()[1]), i == 0)
    heapq.heappush(knights, knight)

currentYear = 0;
currentYearKnights = []
competingKnights = []

karlWon = False;

for i in range(n + k - 2 + 1):
    nextKnight = heapq.heappop(knights)
    nextKnight.competeStrength = True

    if currentYear == 0:
        currentYear = nextKnight.year
    elif currentYear != nextKnight.year:
        knightThatWon = heapq.heappop(competingKnights)
        if knightThatWon.isKarl:
            print(str(currentYear))
            karlWon = True

    currentYear = nextKnight.year;
    heapq.heappush(competingKnights, nextKnight)

if not karlWon:
    knightThatWon = heapq.heappop(competingKnights)
    if knightThatWon.isKarl:
        print(currentYear)
    else:
        print("unknown")