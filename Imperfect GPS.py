class IntervalData:
    x = 0;
    y = 0;
    t = 0;

    def __init__(self, x, y, t):
        self.x = x;
        self.y = y;
        self.t = int(t);

    def __str__(self):
        return str(self.x) + " " + str(self.y) + " " + str(self.t);

def calculateDist(intervals):
    calcDist = 0;

    for i in range(1, len(intervals)):
        calcDist += ((intervals[i].x - intervals[i-1].x)**2 + (intervals[i].y - intervals[i-1].y)**2)**0.5

    return calcDist

def interpolate(i1, i2, amount):
    return [i1.x + amount * (i2.x - i1.x), i1.y + amount * (i2.y - i1.y)]

inp = input()
n, interval = int(inp.split()[0]), int(inp.split()[1])

recordedIntervals = []


for i in range(n):
    line = input()
    x = int(line.split()[0])
    y = int(line.split()[1])
    t = int(line.split()[2])
    recordedIntervals.append(IntervalData(x, y, t))

currentTime = interval
currentIntervalIndex = 0;

gpsReadings = [recordedIntervals[0]]

while currentTime < recordedIntervals[len(recordedIntervals) - 1].t:
    while currentTime > recordedIntervals[currentIntervalIndex].t:
        currentIntervalIndex += 1;

    interpolation = (currentTime - recordedIntervals[currentIntervalIndex - 1].t) / (recordedIntervals[currentIntervalIndex].t - recordedIntervals[currentIntervalIndex - 1].t)

    [x,y] = interpolate(recordedIntervals[currentIntervalIndex-1], recordedIntervals[currentIntervalIndex], interpolation)

    gpsReadings.append(IntervalData(x, y, currentTime))
    currentTime += interval

gpsReadings.append(recordedIntervals[len(recordedIntervals) - 1])

realDist = calculateDist(recordedIntervals)
gpsDist = calculateDist(gpsReadings)

delta = abs(realDist - gpsDist)
deltaPercentage = delta/realDist;
print(deltaPercentage * 100)