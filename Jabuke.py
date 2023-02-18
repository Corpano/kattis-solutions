class Triangle:
    x1 = 0
    y1 = 0

    x2 = 0
    y2 = 0

    x3 = 0
    y3 = 0

    def __init__(self, x1, y1, x2, y2, x3, y3):
        self.x1 = x1;
        self.x2 = x2;
        self.x3 = x3;

        self.y1 = y1;
        self.y2 = y2;
        self.y3 = y3;

def area(triangle):
    return abs(triangle.x1*(triangle.y2-triangle.y3) + triangle.x2 * (triangle.y3 - triangle.y1) + triangle.x3 * (triangle.y1 - triangle.y2))/2

def IsPointInsideTriangle(triangle, point):
    A = area(triangle)

    A1 = area(Triangle(triangle.x2, triangle.y2, point[0], point[1], triangle.x3, triangle.y3))

    A2 = area(Triangle(triangle.x1, triangle.y1, point[0], point[1], triangle.x3, triangle.y3));

    A3 = area(Triangle(triangle.x1, triangle.y1, triangle.x2, triangle.y2, point[0], point[1]))

    return (A == A1 + A2 + A3)

line1 = input()
line2 = input()
line3 = input()

trig = Triangle(int(line1.split()[0]), int(line1.split()[1]), int(line2.split()[0]), int(line2.split()[1]), int(line3.split()[0]), int(line3.split()[1]))
n = int(input())

print(area(trig))

innerPointsCount = 0

for i in range(n):
    line = input()
    point = [int(line.split()[0]), int(line.split()[1])]
    if IsPointInsideTriangle(trig, point):
        innerPointsCount += 1;

print(innerPointsCount)