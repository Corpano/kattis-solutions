#include <iostream>
#include <vector>


using namespace std;

int main() {

    int numOfSets;
    cin >> numOfSets;

    int num;
    for (int i = 0; i < numOfSets; i++) {
        int n;
        int m;
        cin >> n >> m;

        int maxSum = 0;
        int currSum = 0;
        int sumRightOfM = 0;
        bool foundM = false;

        for (int x = 0; x < n; x++) {
            cin >> num;

            if (num == m) {
                if (!foundM) {
                    currSum += num;

                    if (currSum > maxSum) {
                        maxSum = currSum;
                    }

                    foundM = true;
                    sumRightOfM = 0;
                    continue;
                }
                else
                {
                    currSum = sumRightOfM + num;

                    if (currSum > maxSum) {
                        maxSum = currSum;
                    }

                    sumRightOfM = 0;
                    continue;
                }
            }
            else if (num < m) {
                if (foundM && currSum > maxSum) {
                    maxSum = currSum;
                }

                sumRightOfM = 0;
                currSum = 0;
                foundM = false;
                continue;
            }
            else if (num > m) {
                currSum += num;
                if (foundM && currSum > maxSum) {
                    maxSum = currSum;
                }

                sumRightOfM += num;
                continue;
            }
        }

        cout << maxSum << endl;
    }

    return 0;
}