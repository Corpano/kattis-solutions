#include <bits/stdc++.h>
#include <iostream>
#include <vector>;
using namespace std;

int primeFactorsCount(int n)
{
    if(n == 0)
    {
        return 0;
    }

    unordered_set<int> factors;

    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        factors.insert(2);
        n = n/2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            if(!factors.count(i))
            {
                factors.insert(i);
            }

            n = n/i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
    {
        if(!factors.count(n))
        {
            factors.insert(n);
        }
    }

    return factors.size();
}

vector<int> calculatedExcess;
int main() {

    int excessCount = 0;
    for(int i = 0; i < 10000001; i++){
        if(primeFactorsCount(i) % 2 == 0){
            excessCount = excessCount + 1;
        }else{
            excessCount = excessCount - 1;
        }

        calculatedExcess.push_back(excessCount);
    }

    int min, max;
    cin >> min >> max;
    while(!cin.eof()){
        cout << calculatedExcess[max] - calculatedExcess[min - 1] << endl;
        cin >> min >> max;
    }

    return 0;
}
