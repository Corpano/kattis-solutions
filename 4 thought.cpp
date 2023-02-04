#include <iostream>
#include <array>

using namespace std;

class Equation {
public: string equation;
public: int answer;
};

int main() {
    Equation equations[256];
    //    int curr = 0;
    //    for(int first = 0; first < 4; first++){
    //        for(int second = 0; second < 4; second++){
    //            for(int third = 0; third < 4; third++){
    //                string fChar = first == 0 ? "+" : (first == 1 ? "-" : (first == 2 ? "*" : "/"));
    //                string sChar = second == 0 ? "+" : (second == 1 ? "-" : (second == 2 ? "*" : "/"));
    //                string tChar = third == 0 ? "+" : (third == 1 ? "-" : (third == 2 ? "*" : "/"));
    //                string eq = "4 " + fChar + " 4 " + sChar + " 4 " + tChar + " 4";
    //                cout << "equations[" << curr << "] = {equation:\"" << eq << "\", answer:" << eq << "};" << endl;
    //                ++curr;
    //            }
    //        }
    //    }

    equations[0] = { equation:"4 + 4 + 4 + 4", answer : 4 + 4 + 4 + 4 };
    equations[1] = { equation:"4 + 4 + 4 - 4", answer : 4 + 4 + 4 - 4 };
    equations[2] = { equation:"4 + 4 + 4 * 4", answer : 4 + 4 + 4 * 4 };
    equations[3] = { equation:"4 + 4 + 4 / 4", answer : 4 + 4 + 4 / 4 };
    equations[4] = { equation:"4 + 4 - 4 + 4", answer : 4 + 4 - 4 + 4 };
    equations[5] = { equation:"4 + 4 - 4 - 4", answer : 4 + 4 - 4 - 4 };
    equations[6] = { equation:"4 + 4 - 4 * 4", answer : 4 + 4 - 4 * 4 };
    equations[7] = { equation:"4 + 4 - 4 / 4", answer : 4 + 4 - 4 / 4 };
    equations[8] = { equation:"4 + 4 * 4 + 4", answer : 4 + 4 * 4 + 4 };
    equations[9] = { equation:"4 + 4 * 4 - 4", answer : 4 + 4 * 4 - 4 };
    equations[10] = { equation:"4 + 4 * 4 * 4", answer : 4 + 4 * 4 * 4 };
    equations[11] = { equation:"4 + 4 * 4 / 4", answer : 4 + 4 * 4 / 4 };
    equations[12] = { equation:"4 + 4 / 4 + 4", answer : 4 + 4 / 4 + 4 };
    equations[13] = { equation:"4 + 4 / 4 - 4", answer : 4 + 4 / 4 - 4 };
    equations[14] = { equation:"4 + 4 / 4 * 4", answer : 4 + 4 / 4 * 4 };
    equations[15] = { equation:"4 + 4 / 4 / 4", answer : 4 + 4 / 4 / 4 };
    equations[16] = { equation:"4 - 4 + 4 + 4", answer : 4 - 4 + 4 + 4 };
    equations[17] = { equation:"4 - 4 + 4 - 4", answer : 4 - 4 + 4 - 4 };
    equations[18] = { equation:"4 - 4 + 4 * 4", answer : 4 - 4 + 4 * 4 };
    equations[19] = { equation:"4 - 4 + 4 / 4", answer : 4 - 4 + 4 / 4 };
    equations[20] = { equation:"4 - 4 - 4 + 4", answer : 4 - 4 - 4 + 4 };
    equations[21] = { equation:"4 - 4 - 4 - 4", answer : 4 - 4 - 4 - 4 };
    equations[22] = { equation:"4 - 4 - 4 * 4", answer : 4 - 4 - 4 * 4 };
    equations[23] = { equation:"4 - 4 - 4 / 4", answer : 4 - 4 - 4 / 4 };
    equations[24] = { equation:"4 - 4 * 4 + 4", answer : 4 - 4 * 4 + 4 };
    equations[25] = { equation:"4 - 4 * 4 - 4", answer : 4 - 4 * 4 - 4 };
    equations[26] = { equation:"4 - 4 * 4 * 4", answer : 4 - 4 * 4 * 4 };
    equations[27] = { equation:"4 - 4 * 4 / 4", answer : 4 - 4 * 4 / 4 };
    equations[28] = { equation:"4 - 4 / 4 + 4", answer : 4 - 4 / 4 + 4 };
    equations[29] = { equation:"4 - 4 / 4 - 4", answer : 4 - 4 / 4 - 4 };
    equations[30] = { equation:"4 - 4 / 4 * 4", answer : 4 - 4 / 4 * 4 };
    equations[31] = { equation:"4 - 4 / 4 / 4", answer : 4 - 4 / 4 / 4 };
    equations[32] = { equation:"4 * 4 + 4 + 4", answer : 4 * 4 + 4 + 4 };
    equations[33] = { equation:"4 * 4 + 4 - 4", answer : 4 * 4 + 4 - 4 };
    equations[34] = { equation:"4 * 4 + 4 * 4", answer : 4 * 4 + 4 * 4 };
    equations[35] = { equation:"4 * 4 + 4 / 4", answer : 4 * 4 + 4 / 4 };
    equations[36] = { equation:"4 * 4 - 4 + 4", answer : 4 * 4 - 4 + 4 };
    equations[37] = { equation:"4 * 4 - 4 - 4", answer : 4 * 4 - 4 - 4 };
    equations[38] = { equation:"4 * 4 - 4 * 4", answer : 4 * 4 - 4 * 4 };
    equations[39] = { equation:"4 * 4 - 4 / 4", answer : 4 * 4 - 4 / 4 };
    equations[40] = { equation:"4 * 4 * 4 + 4", answer : 4 * 4 * 4 + 4 };
    equations[41] = { equation:"4 * 4 * 4 - 4", answer : 4 * 4 * 4 - 4 };
    equations[42] = { equation:"4 * 4 * 4 * 4", answer : 4 * 4 * 4 * 4 };
    equations[43] = { equation:"4 * 4 * 4 / 4", answer : 4 * 4 * 4 / 4 };
    equations[44] = { equation:"4 * 4 / 4 + 4", answer : 4 * 4 / 4 + 4 };
    equations[45] = { equation:"4 * 4 / 4 - 4", answer : 4 * 4 / 4 - 4 };
    equations[46] = { equation:"4 * 4 / 4 * 4", answer : 4 * 4 / 4 * 4 };
    equations[47] = { equation:"4 * 4 / 4 / 4", answer : 4 * 4 / 4 / 4 };
    equations[48] = { equation:"4 / 4 + 4 + 4", answer : 4 / 4 + 4 + 4 };
    equations[49] = { equation:"4 / 4 + 4 - 4", answer : 4 / 4 + 4 - 4 };
    equations[50] = { equation:"4 / 4 + 4 * 4", answer : 4 / 4 + 4 * 4 };
    equations[51] = { equation:"4 / 4 + 4 / 4", answer : 4 / 4 + 4 / 4 };
    equations[52] = { equation:"4 / 4 - 4 + 4", answer : 4 / 4 - 4 + 4 };
    equations[53] = { equation:"4 / 4 - 4 - 4", answer : 4 / 4 - 4 - 4 };
    equations[54] = { equation:"4 / 4 - 4 * 4", answer : 4 / 4 - 4 * 4 };
    equations[55] = { equation:"4 / 4 - 4 / 4", answer : 4 / 4 - 4 / 4 };
    equations[56] = { equation:"4 / 4 * 4 + 4", answer : 4 / 4 * 4 + 4 };
    equations[57] = { equation:"4 / 4 * 4 - 4", answer : 4 / 4 * 4 - 4 };
    equations[58] = { equation:"4 / 4 * 4 * 4", answer : 4 / 4 * 4 * 4 };
    equations[59] = { equation:"4 / 4 * 4 / 4", answer : 4 / 4 * 4 / 4 };
    equations[60] = { equation:"4 / 4 / 4 + 4", answer : 4 / 4 / 4 + 4 };
    equations[61] = { equation:"4 / 4 / 4 - 4", answer : 4 / 4 / 4 - 4 };
    equations[62] = { equation:"4 / 4 / 4 * 4", answer : 4 / 4 / 4 * 4 };
    equations[63] = { equation:"4 / 4 / 4 / 4", answer : 4 / 4 / 4 / 4 };


    int count;
    cin >> count;

    for (int i = 0; i < count; i++) {
        int num;
        cin >> num;

        for (int x = 0; x < 64; x++) {
            if (equations[x].answer == num) {
                cout << equations[x].equation << " = " << num << endl;
                break;
            }

            if (x == 63) {
                cout << "no solution" << endl;
            }
        }
    }
}