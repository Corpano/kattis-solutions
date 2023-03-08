import sys


def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

for line in sys.stdin:
    maxFactorsMap = {}
    for numStr in line.split():
        num = int(numStr)
        factorsCountMap = {}
        factors = prime_factors(num);

        # numMap[factor] = numFactors
        for factor in factors:
            if factor in factorsCountMap.keys():
                factorsCountMap[factor] = factorsCountMap[factor] + 1
            else:
                factorsCountMap[factor] = 1;

        for factorKey in factorsCountMap.keys():
            if factorKey in maxFactorsMap:
                factorsCountNum = factorsCountMap[factorKey]
                if factorsCountNum > maxFactorsMap[factorKey]:
                    maxFactorsMap[factorKey] = factorsCountNum;

            else:
                maxFactorsMap[factorKey] = factorsCountMap[factorKey];

    product = 1
    for factorKey in maxFactorsMap:
        product *= factorKey**maxFactorsMap[factorKey]

    print(product)