#include <iostream>
#include <array>
#include <unordered_set>
#include <vector>

using namespace std;

class TelephoneCall {
public: int source;
public: int destination;
public: int start;
public: int duration;
};

class Interval {
public: int start;
public: int duration;
};

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        vector<TelephoneCall> telephoneCalls;
        for (int nn = 0; nn < n; nn++) {
            TelephoneCall tc;

            cin >> tc.source >> tc.destination >> tc.start >> tc.duration;
            telephoneCalls.push_back(tc);
        }

        vector<Interval> intervals;
        for (int mm = 0; mm < m; mm++) {
            Interval i;
            cin >> i.start >> i.duration;
            intervals.push_back(i);
        }


        for (int mm = 0; mm < m; mm++) {
            int start = intervals[mm].start;
            int end = start + intervals[mm].duration;

            int sum = 0;
            for (int nn = 0; nn < n; nn++) {
                int callStart = telephoneCalls[nn].start;
                int callEnd = telephoneCalls[nn].start + telephoneCalls[nn].duration;

                if ((callStart < end && callEnd > start)) {
                    ++sum;
                }
            }

            cout << sum << endl;
        }
    }
}
