#include <iostream>
#include <array>

using namespace std;


class Helper {
public: int numOfDifferences(string s1, string s2) {
    int sum = 0;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            sum++;
        }
    }

    return sum;
};
};

int main() {
    int n;
    int m;
    int k;

    cin >> n >> m >> k;
    array<string, 1800> arrC;
    for (int i = 0; i < n; i++) {
        cin >> arrC[i];
    }

    Helper h;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < n; x++) {
            if (x != i) {
                if (h.numOfDifferences(arrC[i], arrC[x]) != k) {
                    break;
                }
            }

            if (x == n - 1) {
                cout << to_string((i + 1));
                return 0;
            }
        }
    }

    return 0;
};