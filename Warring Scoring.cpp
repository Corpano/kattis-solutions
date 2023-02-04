#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <valarray>

using namespace std;

int main() {

    int n;
    cin >> n;

    int yraglacPoints = 0;
    int notnomdePoints = 0;
    int yraglacStreak = 0;
    int notnomdeStreak = 0;
    int yraglacDiff = 0;
    int notnomdeDiff = 0;
    int yMaxStreak = 0;
    int nMaxStreak = 0;

    for (int i = 0; i < n; i++) {
        string next;
        cin >> next;

        if (std::equal(next.begin(), next.end(), "Yraglac")) {
            notnomdeStreak = 0;

            ++yraglacStreak;
            ++yraglacPoints;
        }
        else {
            yraglacStreak = 0;

            ++notnomdeStreak;
            ++notnomdePoints;
        }

        if (yraglacStreak > yMaxStreak) {
            yMaxStreak = yraglacStreak;
        }

        if (notnomdeStreak > nMaxStreak) {
            nMaxStreak = notnomdeStreak;
        }

        if (yraglacPoints - notnomdePoints > yraglacDiff) {
            yraglacDiff = yraglacPoints - notnomdePoints;
        }

        if (notnomdePoints - yraglacPoints > notnomdeDiff) {
            notnomdeDiff = notnomdePoints - yraglacPoints;
        }

    }

    // Notnomde's rules
    bool nTie = yMaxStreak == nMaxStreak;
    bool nYWon = yMaxStreak > nMaxStreak;

    // Yraglac's rules
    bool yTie = yraglacDiff == notnomdeDiff;
    bool yYWon = yraglacDiff > notnomdeDiff;

    if ((nTie || yTie))
    {
        cout << (nTie == yTie ? "Agree" : "Disagree") << endl;
    }
    else if (nYWon == yYWon) {
        cout << "Agree" << endl;
    }
    else {
        cout << "Disagree" << endl;
    }



    return 0;
}