#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

void uva_10038() {
    int n;
    while (cin >> n, !cin.fail()) {
        vector<bool> diffs;
        diffs.resize(n - 1);

        bool jolly = true;
        int prev;
        cin >> prev;

        for (int i = 1; i < n; i++) {
            int curr;
            cin >> curr;

            int diff = abs(prev - curr);
            if (diff < 1 || diff >= n) {
                jolly = false;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            else {
                diffs[diff - 1] = true;
            }

            prev = curr;
        }

        if (jolly) {
            for (int i = 0; i < n - 1; i++) {
                if (!diffs[i]) {
                    jolly = false;
                    break;
                }
            }
        }
        
        cout << (jolly ? "Jolly" : "Not jolly") << "\n";
    }
}
