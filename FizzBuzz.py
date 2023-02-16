fizzDiv, buzzDiv, upper = input().split()

nums = []
for i in range(1, int(upper)+1):
    if i % int(fizzDiv) == 0 and i % int(buzzDiv) == 0:
        nums.append("FizzBuzz")
    elif i % int(fizzDiv) == 0:
        nums.append("Fizz")
    elif i % int(buzzDiv) == 0:
        nums.append("Buzz")
    else:
        nums.append(i)

print(*nums, sep="\n")

