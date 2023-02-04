#include <iostream>
#include <vector>
#include <array>
#include <unordered_set>
#include <valarray>
#include <set>
#include <list>
#include <map>
#include <queue>
#include <stack>


using namespace std;

int startRow, startCol, endRow, endCol;
int rowCount, colCount;
int isDecimal;
vector<vector<int>> grid;

int nextValEven = 2;
int nextValOdd = 3;
int nextVal;

int GetGrid(int r, int c) {
    return grid[r][c];
}

void SetGrid(int r, int c, int val) {
    grid[r][c] = val;
}

bool inRange(int r, int c) {
    return r >= 0 && r < rowCount&& c >= 0 && c < colCount;
}

bool isSafe(int r, int c) {
    return inRange(r, c) && GetGrid(r, c) == isDecimal;
}

void Fill(int r, int c) {
    SetGrid(r, c, nextVal);
}

void FillField(int r, int c) {
    if (GetGrid(r, c) > 1) {
        return;
    }

    isDecimal = GetGrid(r, c);
    if (isDecimal) {
        nextValEven += 2;
        nextVal = nextValEven;
    }
    else {
        nextValOdd += 2;
        nextVal = nextValOdd;
    }

    queue<pair<int, int>> Q;
    Q.push(make_pair(r, c));
    while (!Q.empty()) {
        pair<int, int> n = Q.front();
        Q.pop();

        if (isSafe(n.first, n.second)) {
            Fill(n.first, n.second);

            int nextR = n.first;
            int nextC = n.second - 1;
            if (isSafe(nextR, nextC)) {
                Q.push(make_pair(nextR, nextC));
            }

            nextR = n.first;
            nextC = n.second + 1;
            if (isSafe(nextR, nextC)) {
                Q.push(make_pair(nextR, nextC));
            }

            nextR = n.first + 1;
            nextC = n.second;
            if (isSafe(nextR, nextC)) {
                Q.push(make_pair(nextR, nextC));
            }

            nextR = n.first - 1;
            nextC = n.second;
            if (isSafe(nextR, nextC)) {
                Q.push(make_pair(nextR, nextC));
            }
        }
    }
}

int main() {
    cin >> rowCount >> colCount;

    char val;
    grid.resize(rowCount);
    for (int r = 0; r < rowCount; r++) {
        grid[r].resize(colCount);
        for (int c = 0; c < colCount; c++) {
            cin >> val;
            grid[r][c] = (val == '1' ? 1 : 0);
        }
    }

    for (int r = 0; r < rowCount; r++) {
        for (int c = 0; c < colCount; c++) {
            FillField(r, c);
        }
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> startRow >> startCol >> endRow >> endCol;
        --startRow; --startCol; --endRow; --endCol;

        if (GetGrid(startRow, startCol) == GetGrid(endRow, endCol)) {
            cout << ((GetGrid(startRow, startCol) % 2 == 0) ? "decimal" : "binary") << endl;
        }
        else
        {
            cout << "neither" << endl;
        }

    }

    return 0;
}