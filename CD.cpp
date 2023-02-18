#include <iostream>;
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    while (true) {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0) {
            return 0;
        }

        int counter = 0;
        unordered_set<int> jack;
        for (int i = 0; i < n; i++) {
            int next;
            cin >> next;
            jack.insert(next);
        }

        for (int j = 0; j < m; j++) {
            int next;
            cin >> next;
            if (jack.count(next)) {
                counter += 1;
            }
        }

        cout << counter << endl;
    }

    return 0;
}