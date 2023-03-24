inp = input()

ranks = {}

for i in inp.split():
    if i[0] in ranks.keys():
        ranks[i[0]] += 1;
    else:
        ranks[i[0]] = 1;

max = -1;
for k in ranks.keys():
    if ranks[k] > max:
        max = ranks[k]

print(max)
