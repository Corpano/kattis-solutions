#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int totalAwakeTime = 0;
    int coffesLeft = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            coffesLeft = 2;
            totalAwakeTime++;
        }
        else if (coffesLeft > 0)
        {
            coffesLeft--;
            totalAwakeTime++;
        }
    }

    cout << totalAwakeTime;

    return 0;
}