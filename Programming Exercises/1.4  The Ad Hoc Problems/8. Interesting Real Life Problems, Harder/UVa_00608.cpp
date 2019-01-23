#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void uva_00608() {
    int tc;
    string left, right, rightLevel;
    cin >> tc;
    while (tc--) {
        unordered_map<char, bool> real;
        string unfilteredHeavy = "";
        string unfilteredLight = "";
        int unevenCount = 0;
        int data = 3;
        while (data--) {
            cin >> left;
            cin >> right;
            cin >> rightLevel;

            int n = left.size();
            if (rightLevel.compare("up") == 0) {
                unfilteredHeavy += left;
                unfilteredLight += right;
                unevenCount++;
            }
            else if (rightLevel.compare("down") == 0) {
                unfilteredHeavy += right;
                unfilteredLight += left;
                unevenCount++;
            }
            else {
                while (n--) {
                    real[left[n]] = true;
                    real[right[n]] = true;
                }
            }
        }

        string heavy = "";
        string light = "";
        for (char c : unfilteredHeavy) {
            if (!real[c])
                heavy += c;
        }
        for (char c : unfilteredLight) {
            if (!real[c])
                light += c;
        }

        bool found = false;
        unordered_map<char, int> counter;
        for (char c : heavy) {
            counter[c] += 1;
            if (counter[c] == unevenCount) {
                cout << c << " is the counterfeit coin and it is heavy.\n";
                found = true;
                break;
            }
        }

        if (found)
            continue;

        counter.clear();
        for (char c : light) {
            counter[c] += 1;
            if (counter[c] == unevenCount) {
                cout << c << " is the counterfeit coin and it is light.\n";
                break;
            }
        }
    }
}
