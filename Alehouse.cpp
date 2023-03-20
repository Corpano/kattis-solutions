#include <iostream>;
#include <bits/stdc++.h>

using namespace std;

struct TimeInterval {
public:
    bool isStart;
    int time;
    int guest;
};

int main(){
    int n,k;
    cin >> n >> k;

    vector<TimeInterval> timeIntervals;
    vector<int> leaveTimes;

    for (int i = 0; i < n; i++){
        int start, end;
        cin >> start >> end;

        timeIntervals.push_back(TimeInterval({true, start, i}));
        timeIntervals.push_back(TimeInterval({false, end, i}));
        leaveTimes.push_back(end);
    }

    std::sort(leaveTimes.begin(), leaveTimes.end());
    std::sort(timeIntervals.begin(), timeIntervals.end(), [] (TimeInterval t1, TimeInterval t2){ return t1.time < t2.time; });

    int guestCount = 0;
    int max = 0;

    int rightCursor = 0;
    int leftCursor = 0;

    int visitBeginTime = leaveTimes[0];
    int currBeginTimeIndex = 0;

    while(true){
        while(timeIntervals[rightCursor].time <= visitBeginTime + k){
            if(timeIntervals[rightCursor].isStart)
            {
                ++guestCount;
            }
            ++rightCursor;

            if(rightCursor > timeIntervals.size()){
                break;
            }
        }

        while(timeIntervals[leftCursor].time < visitBeginTime){
            if(!timeIntervals[leftCursor].isStart)
            {
                -- guestCount;
            }
            ++leftCursor;
        }

        ++currBeginTimeIndex;
        visitBeginTime = leaveTimes[currBeginTimeIndex];

        if(guestCount > max){
            max = guestCount;
        }

        if(rightCursor > timeIntervals.size()){
            break;
        }
    }

    cout << max;
    return 0;
}
