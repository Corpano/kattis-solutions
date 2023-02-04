#include <iostream>
#include <vector>
#include <array>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;

        if (i % 2 == 0)
            cout << word << endl;
    }

    return 0;
}