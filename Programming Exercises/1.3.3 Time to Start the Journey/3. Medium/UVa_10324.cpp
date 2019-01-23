#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void uva_10324() {
    string s;
    int n, i, j, left, right, prev, tc = 0;
    while (cin >> s, !cin.fail()) {
        cout << "Case " << ++tc << ":\n";
        cin >> n;
        while (n--) {
            cin >> i;
            cin >> j;
            left = min(i, j);
            right = max(i, j);
            j = 1;
            for (i = left; i <= right; i++) {
                if (i != left && prev != s[i]) {
                    j = 0;
                    break;
                }
                prev = s[i];
            }
            cout << (j ? "Yes" : "No") << "\n";
        }
    }
}
