#include <iostream>
#include <array>
#include <list>

using namespace std;

int main() {
    int num;
    int sum = 0;
    cin >> num;

    for (int i = 0; i < num; i++) {
        int n;
        cin >> n;

        if (n < 0) {
            sum = sum - n;
        }
    }

    std::cout << sum;

    return 0;
}
