#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

void uva_11389() {
    int n, d, r;
    while (cin >> n, cin >> d, cin >> r, n || d || r) {
        int morning[100], afternoon[100];
        for (int i = 0; i < n; i++)
            cin >> morning[i];
        for (int i = 0; i < n; i++)
            cin >> afternoon[i];
        sort(morning, morning + n);
        sort(afternoon, afternoon + n, greater<int>());

        int total = 0;
        for (int i = 0; i < n; i++) {
            int m = morning[i];
            int a = afternoon[i];
            if (m + a > d)
                total += (m + a - d) * r;
        }

        cout << total << "\n";
    }
}
