#include <iostream>
#include <functional>

using namespace std;

void uva_00416() {
    const int digits[] = { 63, 6, 91, 79, 102, 109, 125, 7, 127, 111 };

    int n;
    while (cin >> n, n) {
        int displays[10] = { 0 };

        for (int i = 0; i < n; i++) {
            char display[8];
            cin >> display;

            for (int j = 0; j < 7; j++) {
                if (display[j] == 'Y')
                    displays[i] |= (1 << j);
            }
        }

        bool match = false;

        for (int d = 9; d >= n - 1; d--) {
            int burnout = 0;
            bool valid = true;
            for (int di = 0; di < n; di++) {
                if ((~digits[d - di] & displays[di])
                    || (burnout & digits[d - di] & displays[di])) {
                    valid = false;
                    break;
                }
                burnout |= digits[d - di] & ~displays[di];
            }
            if (valid) {
                match = true;
                break;
            }
        }

        cout << (!match ? "MIS" : "") << "MATCH\n";
    }
}
