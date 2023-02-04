#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

struct Pizza {
public:
    string name;
    vector<string> italianIngridients;
    vector<string> englishIngridients;
};

int main() {
    int numOfTestCases;
    cin >> numOfTestCases;

    while (numOfTestCases > 0) {

        int numOfPizzas;
        cin >> numOfPizzas;
        map<string, map<string, int>> ingMap;

        vector<Pizza> pizzas;
        for (int i = 0; i < numOfPizzas; i++) {
            string pizzaName;
            cin >> pizzaName;

            Pizza p = { pizzaName };

            int n1, n2;
            cin >> n1;

            string nextIng;
            for (int i = 0; i < n1; i++) {
                cin >> nextIng;
                p.italianIngridients.push_back(nextIng);
            }

            cin >> n2;
            for (int i = 0; i < n2; i++) {
                cin >> nextIng;
                p.englishIngridients.push_back(nextIng);
            }


            for (int i = 0; i < n1; i++) {
                for (int x = 0; x < n2; x++) {
                    string currItaly = p.italianIngridients[i];
                    string currEng = p.englishIngridients[x];

                    if (ingMap.count(currItaly)) {
                        if (ingMap[currItaly].count(currEng)) {
                            ingMap[currItaly][currEng] = ingMap[currItaly][currEng] + 1;
                        }
                        else {
                            ingMap[currItaly][currEng] = 1;
                        }
                    }
                    else {
                        ingMap[currItaly] = map<string, int>();
                        ingMap[currItaly][currEng] = 1;
                    }
                }
            }

            pizzas.push_back(p);
        }

        for (auto it = ingMap.begin(); it != ingMap.end(); ++it) {
            for (auto it2 = ingMap[it->first].begin(); it2 != ingMap[it->first].end(); ++it2) {
                //                cout << "====" << it->first << " " << it2->first << " " << it2->second << endl;

                if (it2->second > 0) {

                    bool hasEng = true;
                    bool hasIta = true;

                    for (int i = 0; i < pizzas.size(); i++) {
                        bool currentIta = false;
                        bool currentEng = false;
                        for (auto engIng : pizzas[i].englishIngridients) {
                            if (engIng == it2->first) {
                                currentEng = true;
                            }
                        }

                        for (auto itaIng : pizzas[i].italianIngridients) {
                            if (itaIng == it->first) {
                                currentIta = true;
                            }
                        }

                        if (currentIta != currentEng) {
                            hasEng = false;
                            hasIta = false;
                        }
                    }

                    if (hasIta == true && hasEng == true)
                        cout << "(" << it->first << ", " << it2->first << ")" << endl;
                }
            }
        }

        cout << endl;

        numOfTestCases--;
    }

    return 0;
}