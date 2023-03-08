n = int(input())

for i in range(n):
    attrCount = int(input())
    attrGroups = {}

    for a in range(attrCount):
        line = input().split()
        attrGroup = line[1]

        if attrGroup in attrGroups:
            attrGroups[attrGroup] = attrGroups[attrGroup] + 1
        else:
            attrGroups[attrGroup] = 1;

    sum = attrCount;
    product = 1
    for key in attrGroups.keys():
        product *= attrGroups[key] + 1

    print(product-1)