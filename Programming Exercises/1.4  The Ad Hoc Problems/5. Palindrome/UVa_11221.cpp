#include <iostream>
#include <limits>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

void uva_11221() {
    int tc;
    cin >> tc;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int caseNum = 1; caseNum <= tc; caseNum++) {
        cout << "Case #" << caseNum << ":\n";

        string line;
        getline(cin, line);
        
        bool invalidString = false;
        string clean;
        for (int i = 0, n = line.size(); i < n; i++) {
            char c = line[i];
            if (!isalpha(c) && c != ' '
                && c != ',' && c != '.' && c != '?'
                && c != '!' && c != '(' && c != ')') {
                invalidString = true;
                break;
            }
            if (isalpha(c))
                clean += c;
        }

        if (!invalidString) {
            for (int i = 0, n = clean.size(); i < n / 2; i++) {
                if (clean[i] != clean[n - 1 - i])
                    invalidString = true;
            }
        }

        if (invalidString) {
            cout << "No magic :(\n";
            continue;
        }

        int n = clean.size();
        double lineSize = sqrt(n);
        if (floor(lineSize) - lineSize == 0) {
            bool valid = true;
            int cursor = 0;
            for (int i = 0; i < lineSize; i++) {
                for (int j = 0; j < n; j += (int)lineSize) {
                    if (clean[cursor++] != clean[j + i]) {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid)
                cout << (int)lineSize << "\n";
            else
                cout << "No magic :(\n";
        }
        else {
            cout << "No magic :(\n";
        }
    }
}
