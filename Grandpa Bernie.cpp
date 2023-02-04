#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <valarray>
#include <unordered_map>

using namespace std;

int main() {

    int n;
    cin >> n;

    unordered_map<string, vector<int>> mapp;

    for (int i = 0; i < n; i++) {
        string name;
        int yr;

        cin >> name >> yr;

        mapp[name].push_back(yr);
    }

    for (auto kV : mapp) {
        std::sort(mapp[kV.first].begin(), mapp[kV.first].end());
    }

    int c;
    cin >> c;
    for (int i = 0; i < c; i++) {
        string name;
        int id;

        cin >> name >> id;

        cout << mapp[name][id - 1] << endl;
    }

    return 0;
}