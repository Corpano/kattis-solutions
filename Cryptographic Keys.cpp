#include <iostream>
#include <cmath>
using namespace std;

int solve(int n, int b) {
    int count = 0;
        while(true){
            int remainder = n % b;
            if(remainder != 0){
                break;
            }else{
                ++count;
            }

            n /= b;
        }
    return count;
}

int main() {

    int n;
    int b = 2;
    int maxbase = 0;
    int max = 0;
    cin >> n;
    while(b <= n) {
        int val = solve(n, b);
        if(val > max) {
            max = val;
            maxbase = b;
        }
        b++;
    }
    cout << maxbase;
    return 0;
}