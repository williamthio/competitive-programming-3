#include <iostream>

using namespace std;

void uva_11264() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        
        int coins[1000];
        for (int i = 0; i < n; i++) {
            cin >> coins[i];
        };

        if (n < 3) {
            cout << n << "\n";
            continue;
        }

        int count = 1;
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            if (coins[i + 1] > sum + coins[i]) {
                count++;
                sum += coins[i];
            }
        }

        cout << count << "\n";
    }
}
