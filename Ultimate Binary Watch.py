def convertToBinary (num):
    bits = []
    for i in range(3, -1, -1):
        if(num >= 2**i):
            num -= 2**i
            bits.append(1)
        else:
            bits.append(0)
    return bits

inp = input();
n1 = int(inp[0])
n2 = int(inp[1])
n3 = int(inp[2])
n4 = int(inp[3])

table = [convertToBinary(n1), convertToBinary(n2), convertToBinary(n3), convertToBinary(n4)]

output = ""

for i in range(4):
    for j in range(4):
        output += "*" if table[j][i] == 1 else "."

        if j == 1:
            output += "   "
        elif j != 3:
            output += " "
    if(i != 3):
        output += '\n'

print(output)