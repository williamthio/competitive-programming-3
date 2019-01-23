#include <iostream>
#include <ctime>
#include <limits>
#include <string>

using namespace std;

void uva_11661() {
    int l, i, pos, min;
    char c;
    string s;
    while (cin >> l, l) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, s);
        c = '-';
        min = 2000000;
        for (i = 0; i < l; i++) {
            if (s[i] == 'Z') {
                min = 0;
                break;
            }
            if (s[i] == '.')
                continue;
            if (c == '-' || c == s[i]) {
                c = s[i];
                pos = i;
            }
            else {
                if (min > i - pos)
                    min = i - pos;
                c = s[i];
                pos = i;
            }
        }
        cout << min << "\n";
    }
}
