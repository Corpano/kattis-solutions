#include <iostream>
#include <vector>
#include <array>
#include <stack>
#include <queue>
#include <unordered_set>


using namespace std;

// Here's my solution for https://open.kattis.com/problems/illiteracy. I have used Breadth First Search algorithm until it has reached the solution. In order to optimize code I used unordered_set and integer hashing (instead of string). It took 1.75s out of max. 11s on Kattis.

#define SEQ_SIZE 8
class Sequence {
public:
    array<int, SEQ_SIZE> seq;
    int steps = 0;
    void OnClick(int x);
    int Hash();

private:
    bool IsOnEitherEnd(int x);
    void Rotate(int x);
};

bool Sequence::IsOnEitherEnd(int x) {
    return x == 0 || x == seq.size() - 1;
}

void Sequence::Rotate(int x) {
    if (SEQ_SIZE <= x || x < 0)
        return;

    seq[x]++;
    if (seq[x] > 5) {
        seq[x] = 0;
    }
}

void Sequence::OnClick(int x) {
    switch (seq[x]) {
    case 0:
        Rotate(x - 1);
        Rotate(x + 1);
        break;
    case 1:
        if (IsOnEitherEnd(x))
            return;
        seq[x + 1] = int(seq[x - 1]);
        break;
    case 2:
        Rotate((9 - (x + 1)) - 1);
        break;
    case 3:
        if (IsOnEitherEnd(x))
            return;

        if (x <= 3) {
            for (int i = 0; i < x; i++) {
                Rotate(i);
            }
        }
        else {
            for (int i = x + 1; i < seq.size(); i++) {
                Rotate(i);
            }
        }
        break;
    case 4:
        if (IsOnEitherEnd(x))
            return;

        int y;
        if (x <= 3) {
            y = x;
        }
        else {
            y = seq.size() - 1 - x;
        }

        Rotate(x + y);
        Rotate(x - y);
        break;
    case 5:
        if ((x + 1) % 2 != 0) {
            Rotate(((x + 1 + 9) / 2) - 1);
        }
        else {
            Rotate(((x + 1) / 2) - 1);
        }
        break;
    }
}

int Sequence::Hash() {
    return seq[0] * 10000000 + seq[1] * 1000000 + seq[2] * 100000 + seq[3] * 10000 + seq[4] * 1000 + seq[5] * 100 + seq[6] * 10 + seq[7];
}

// Algorithm
// Uses Breadth Search and checks all possible combinations until it finds path to final sequence of characters
void FindSteps(Sequence start, Sequence end) {
    queue<Sequence> Q;
    unordered_set<int> visited;
    int goal = end.Hash();

    // Start and end are the same, return 0
    if (start.Hash() == goal) {
        cout << "0";
        return;
    }

    Q.push(start);
    while (!Q.empty()) {
        Sequence curr = Q.front();
        Q.pop();

        // Each possible combination---check if it's goal, if not add to queue
        for (int i = 0; i < SEQ_SIZE; i++) {
            Sequence newCombination = { array<int, SEQ_SIZE>(curr.seq), (curr.steps + 1) };
            newCombination.OnClick(i);

            int newCombinationHash = newCombination.Hash();
            if (!visited.count(newCombinationHash)) {
                // End if we have reached our final destination
                if (newCombinationHash == goal) {
                    cout << newCombination.steps;
                    return;
                }

                visited.insert(newCombinationHash);
                Q.push(newCombination);
            }
        }
    }
}

int main() {
    Sequence s1 = { steps:0 };
    Sequence s2 = { steps:0 };

    char c;
    // Get sequence no.1
    for (int i = 0; i < SEQ_SIZE; i++) {
        cin >> c;
        // Converts character to integer (A = 0, B = 1, etc.)
        s1.seq[i] = (int)c - 65;
    }

    // Get sequence no.2
    for (int i = 0; i < SEQ_SIZE; i++) {
        cin >> c;
        // Converts character to integer (A = 0, B = 1, etc.)
        s2.seq[i] = (int)c - 65;
    }

    FindSteps(s1, s2);
    return 0;
}