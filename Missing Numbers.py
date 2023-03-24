n = int(input())

expected = 1
wasMissing = False

for i in range(n):
    next = int(input());

    while expected != next:
        print(expected)
        expected += 1;
        wasMissing = True

    expected = next + 1

if not wasMissing:
    print('good job')
