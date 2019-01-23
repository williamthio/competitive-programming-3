#include <iostream>
#include <ctime>
#include <string>

using namespace std;

void uva_11687() {
    string s;
    int x, xprev, i;
    while (getline(cin, s), s.compare("END") != 0) {
        if (s.compare("1") == 0) {
            cout << "1\n";
            continue;
        }
        i = 1;
        x = s.size();
        do {
            xprev = x;
            s = to_string(xprev);
            x = s.size();
            i++;
        } while (xprev != x);
        cout << i << "\n";
    }
}
