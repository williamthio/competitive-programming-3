#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void uva_11991() {
    int n;
    while (cin >> n, !cin.fail()) {
        int m;
        cin >> m;

        unordered_map<int, vector<int>> occurrences;

        for (int i = 1; i <= n; i++) {
            int v;
            cin >> v;
            occurrences[v].push_back(i);
        }

        for (int i = 0; i < m; i++) {
            unsigned int k, v;
            cin >> k;
            cin >> v;
            if (occurrences[v].size() < k) {
                cout << "0\n";
                continue;
            }
            cout << occurrences[v][k - 1] << "\n";
        }
    }
}
