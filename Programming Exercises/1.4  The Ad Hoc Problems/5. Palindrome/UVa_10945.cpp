#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void uva_10945() {
    string line;
    while (getline(cin, line), line.compare("DONE") != 0) {
        string clean = "";
        for (int i = 0, n = line.size(); i < n; i++) {
            if (isalpha(line[i]))
                clean += tolower(line[i]);
        }

        bool eaten = false;
        int n = clean.size();
        for (int i = 0; i < n / 2; i++) {
            if (clean[i] != clean[n - i - 1]) {
                eaten = true;
                break;
            }
        }

        if (eaten)
            cout << "Uh oh..\n";
        else
            cout << "You won't be eaten!\n";
    }
}
