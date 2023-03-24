n = int(input())
first_line = input().replace(' ', '')
second_line = input().replace(' ', '')

curr = 0;

for i in range(len(second_line)):
    if second_line[i].isalpha() and second_line[i] != 'T' and second_line[i] != 'F':
        second_line = second_line.replace(second_line[i], first_line[curr]);
        curr += 1;

i = 0;
while i < len(second_line):
    sign = second_line[i];
    if not sign.isalpha():
        if sign == '*':
            n1 = second_line[i-1]
            n2 = second_line[i-2]
            res = 'F'
            if n1 == 'T' and n2 == 'T':
                res = 'T'

            second_line = second_line[0:i-2] + res + second_line[i+1::]
            i = -1
        elif sign == '+':
            n1 = second_line[i - 1]
            n2 = second_line[i - 2]
            res = 'T'
            if n1 == 'F' and n2 == 'F':
                res = 'F'

            second_line = second_line[0:i - 2] + res + second_line[i + 1::]
            i = -1
        elif sign == '-':
            n1 = second_line[i - 1]
            res = 'F' if n1 == 'T' else 'T';
            second_line = second_line[0:i - 1] + res + second_line[i + 1::]
            i = -1
    i += 1

print(second_line);
