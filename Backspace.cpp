#include <iostream>
#include <array>
#include <unordered_set>

using namespace std;

int main() {
    string input;
    string out;

    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '<') {
            out.pop_back();
        }
        else {
            out += input[i];
        }
    }

    cout << out;
    return 0;
};