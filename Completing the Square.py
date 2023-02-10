import math
import sys


def dist(x1, y1, x2, y2):
    return math.sqrt(((float(x2) - float(x1))**2 + (float(y2) - float(y1))**2))


line1 = input()
line2 = input()
line3 = input()

c1x = int(line1.split()[0])
c1y = int(line1.split()[1])

c2x = int(line2.split()[0])
c2y = int(line2.split()[1])

c3x = int(line3.split()[0])
c3y = int(line3.split()[1])


dist1 = dist(c1x, c1y, c2x, c2y)
dist2 = dist(c1x, c1y, c3x, c3y)
dist3 =  dist(c2x, c2y, c3x, c3y)

def centerBetweenTwoPoints(x1, y1, x2, y2):
    newX = x1 + (x2 - x1) / 2
    newY = y1 + (y2 - y1) / 2
    return [newX, newY]

center = []
finalX, finalY = 0,0

if(dist1 == dist2):
    center = centerBetweenTwoPoints(c3x, c3y, c2x, c2y);
    finalX = c1x + 2 * (center[0] - c1x);
    finalY = c1y + 2 * (center[1] - c1y);

elif(dist1 == dist3):
    center = centerBetweenTwoPoints(c1x, c1y, c3x, c3y);
    finalX = c2x + 2 * (center[0] - c2x);
    finalY = c2y + 2 * (center[1] - c2y);

elif(dist3 == dist2):
    center = centerBetweenTwoPoints(c1x, c1y, c2x, c2y);
    finalX = c3x + 2 * (center[0] - c3x);
    finalY = c3y + 2 * (center[1] - c3y);
else:
    print("Error. Should have two equal distances.");

print(int(finalX), int(finalY))