n = int(input())

for i in range(n):
    k = int(input())
    hasPanckakes, hasPeas = False, False;

    restaurant_name = input();
    for x in range(k):
        line = input()

        if 'pea soup' == line:
            hasPeas = True;
        if 'pancakes' == line:
            hasPanckakes = True;

    if hasPanckakes and hasPeas:
        print(restaurant_name)
        exit(0);

print('Anywhere is fine I guess')
