alphabet = 'abcdefghijklmnopqrstuvwxyz'

def encrypt(s):
    l = [0 if x == ' ' else ord(x) - 96 for x in s]
    for i in range(1, len(l)):
        l[i] = l[i] + l[i - 1]
        l[i] = l[i] % 27

    return ''.join([' ' if x <= 0 else alphabet[x-1] for x in l])

def decrypt(s):
    l = [0 if x == ' ' else ord(x) - 96 for x in s]

    for i in range(len(l)-1, 0, -1):
        l[i]= l[i] - l[i-1]

        if l[i] < 0:
            l[i] += 27

    return ''.join([' ' if x <= 0 else alphabet[x-1] for x in l])

n = int(input())
for i in range(n):
    line = input()
    type = line[0:1]
    s = line[2::]

    if type == 'e':
        print(encrypt(s))
    else:
        print(decrypt(s))
