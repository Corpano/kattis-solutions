numRecorded = int(input())
count = 0

temp = input().split(" ")

for i in range(numRecorded):
    if int(temp[i]) < 0:
        count += 1

print(count)