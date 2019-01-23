#include <iostream>
#include <limits>
#include <string>
#include <ctime>

using namespace std;

void uva_11586() {
    int tc, m, f;
    string s;
    cin >> tc;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (tc--) {
        m = 0;
        f = 0;
        getline(cin, s);
        for (char c : s)
            if (c == 'M')
                m++;
            else if (c == 'F')
                f++;
        cout << (m <= 1 || m != f ? "NO " : "") << "LOOP\n";
    }
}
