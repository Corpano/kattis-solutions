n = input()
val = True

k = n
k = k[::-1]
if k not in n + n + n:
    val = False

print('1' if val == True else '0')