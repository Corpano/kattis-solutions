import sys

decryptedArray = [0] * 256

for i in range(256):
    y = i ^ (i << 1)
    decryptedArray[y%256] = i

n = int(input())

for i in input().split():
    nextNum = int(i)
    print(decryptedArray[nextNum])