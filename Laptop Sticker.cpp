#include <iostream>
using namespace std;

int main() {
    int wc, hc, ws, hs;

    cin >> wc >> hc >> ws >> hs;

    bool width = wc > ws + 1;
    bool height = hc > hs + 1;

    cout << ((width && height) ? 1 : 0);

    return 0;
}