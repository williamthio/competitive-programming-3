#include <iostream>

using namespace std;

void uva_12455() {
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n;
        cin >> p;

        int bars[20];
        for (int i = 0; i < p; i++)
            cin >> bars[i];
        
        int found = false;
        for (int i = 0; i < (1 << p); i++) {
            int sum = 0;
            for (int j = 0; j < p; j++) {
                if (i & (1 << j))
                    sum += bars[j];
            }
            if (sum == n) {
                found = true;
                break;
            }
        }

        cout << (found ? "YES\n" : "NO\n");
    }
}
