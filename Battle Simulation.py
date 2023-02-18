import re

inp = input()

x = re.sub("RLB|RBL|BRL|BLR|LRB|LBR", "C", inp)
x = re.sub("R", "S", x)
x = re.sub("B", "K", x)
x = re.sub("L", "H", x)

print(x)