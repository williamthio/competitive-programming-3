#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

void uva_11572() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int maxLength = 0;
        int i = 0;
        int tail = 0;
        vector<int> ids(n);
        unordered_map<int, int> indexes;
        unordered_map<int, bool> exists;
        for (i = 0; i < n; i++) {
            cin >> ids[i];
            if (exists[ids[i]]) {
                if (maxLength < i - tail)
                    maxLength = i - tail;
                for (int j = tail; j < indexes[ids[i]]; j++)
                    exists[ids[j]] = false;
                tail = indexes[ids[i]] + 1;
                indexes[ids[i]] = i;
            }
            else {
                indexes[ids[i]] = i;
                exists[ids[i]] = true;
            }
        }
        if (maxLength < i - tail) {
            maxLength = i - tail;
        }
        cout << maxLength << "\n";
    }
}
