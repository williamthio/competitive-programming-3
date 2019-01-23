#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void uva_12192() {
    int n, m;
    while (cin >> n, cin >> m, n && m) {
        vector<vector<int>> diagonals;
        diagonals.resize(n + m - 1);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                int h;
                cin >> h;
                diagonals[r - c + m - 1].push_back(h);
            }
        }
        
        int q;
        cin >> q;
        while (q--) {
            int low, high;
            cin >> low;
            cin >> high;
            int max = 0;
            for (int i = 0, dn = n + m - 1; i < dn; i++) {
                vector<int>::iterator begin = diagonals[i].begin();
                vector<int>::iterator end = diagonals[i].end();
                vector<int>::iterator lbitr = lower_bound(begin, end, low);
                int lb = lbitr - begin;
                int ub = upper_bound(lbitr, end, high) - begin;
                if (max < ub - lb)
                    max = ub - lb;
            }
            cout << max << "\n";
        }

        cout << "-\n";
    }
}
