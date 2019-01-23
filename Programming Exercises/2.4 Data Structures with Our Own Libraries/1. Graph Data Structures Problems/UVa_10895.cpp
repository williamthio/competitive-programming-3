#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void uva_10895() {
    int m, n;
    while (cin >> m, !cin.fail()) {
        cin >> n;
        vector<vector<pair<int, int>>> out(n);
        for (int row = 0; row < m; row++) {
            vector<int> cols;
            int colSize;
            cin >> colSize;
            while (colSize--) {
                int col;
                cin >> col;
                cols.push_back(col);
            }
            for (int col : cols) {
                int value;
                cin >> value;
                out[col - 1].push_back(make_pair(row + 1, value));
            }
        }
        cout << n << " " << m << "\n";
        for (int row = 0; row < n; row++) {
            int colSize = out[row].size();
            cout << colSize;
            for (int i = 0; i < colSize; i++)
                cout << " " << out[row][i].first;
            cout << "\n";
            for (int i = 0; i < colSize; i++) {
                if (i > 0)
                    cout << " ";
                cout << out[row][i].second;
            }
            cout << "\n";
        }
    }
}
