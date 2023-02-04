inp = input();

num = int(inp.split()[0])
d1 = int(inp.split()[1])
d2 = int(inp.split()[2])

c = (d1**2+d2**2)**(1/2)

for i in range(num):
    n = int(input());
    if c >= n:
        print("DA")
    else:
        print("NE")