#include <iostream>
#include <vector>

using namespace std;

void uva_10264() {
    int n;
    while (cin >> n, !cin.fail()) {
        vector<int> corners, sums;
        corners.resize(1 << n);
        sums.resize(1 << n);
        for (int i = 0; i < (1 << n); i++)
            cin >> corners[i];

        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                sums[i] += corners[i ^ (1 << j)];
            }
        }

        int max = 0;
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if (max < sums[i] + sums[i ^ (1 << j)])
                    max = sums[i] + sums[i ^ (1 << j)];
            }
        }
        cout << max << "\n";
    }
}
