#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <valarray>

using namespace std;

int main() {
    long double length = pow(2.0, -3.0 / 4.0);
    long double width = pow(2.0, -5.0 / 4.0);

    const long double  initialLength = length;
    const long double initialWidth = width;

    int smallest;
    cin >> smallest;

    int next;
    int needed = 1;
    long double tape = 0.0;

    for (int i = 0; i < smallest - 1; i++) {
        cin >> next;
        needed *= 2;

        if (i != 0) {
            if (i % 2 == 1) {
                length /= 2;
            }
            else {
                width /= 2;
            }
        }

        if (next >= needed) {
            // found;
            tape = tape + needed * (length + width);
            needed -= next;
            break;
        }
        else {
            tape = tape + next * (length + width);
            needed = needed - next;
        }
    }


    cout.precision(100);
    if (needed <= 0) {
        cout << ((tape - (initialLength + initialWidth * 2.0))) << endl;
    }
    else {
        cout << "impossible" << endl;
    }

    return 0;
}