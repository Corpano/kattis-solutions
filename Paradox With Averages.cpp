#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <valarray>
#include <unordered_map>
using namespace std;



double calculateAverage(vector<int> listArr) {
    double sum = 0;
    for (int i = 0; i < listArr.size(); i++) {
        sum += (double)listArr[i];
    }

    return sum / ((double)listArr.size());
}

bool ss(int i, int i1) {
    return i > i1;
}

int main() {
    int numOfTestCases;
    cin >> numOfTestCases;

    for (int i = 0; i < numOfTestCases; i++) {
        int csStudentsCount, econsCount;
        cin >> csStudentsCount >> econsCount;

        vector<int> csIqs;
        vector<int> econIqs;

        int next;
        for (int x = 0; x < csStudentsCount; x++) {
            cin >> next;
            csIqs.push_back(next);
        }

        for (int x = 0; x < econsCount; x++) {
            cin >> next;
            econIqs.push_back(next);
        }

        int total = 0;

        double average = calculateAverage(csIqs);
        double average2 = calculateAverage(econIqs);

        for (int z = 0; z < csIqs.size(); z++) {
            if (((double)csIqs[z]) < average && ((double)csIqs[z]) > average2) {
                total = total + 1;
            }
        }
        cout << total << endl;
    }


    return 0;
}