#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

void uva_01237() {
    int tc;
    cin >> tc;
    for (int ci = 0; ci < tc; ci++) {
        if (ci > 0)
            cout << "\n";

        int d;
        cin >> d;
        vector<pair<pair<int, int>, string>> database(d);
        for (int i = 0; i < d; i++) {
            cin >> database[i].second;
            cin >> database[i].first.first;
            cin >> database[i].first.second;
        }
        sort(database.begin(), database.end());

        function<int(int)> search = [&](int value) -> int {
            int result = -1, count = 0;
            for (int i = 0; i < d; i++) {
                if (database[i].first.first <= value
                    && value <= database[i].first.second) {
                    result = i;
                    if (++count == 2) {
                        result = -1;
                        break;
                    }
                }
            }
            return result;
        };

        int q;
        cin >> q;
        while (q--) {
            int value;
            cin >> value;
            int i = search(value);
            cout << (i == -1 ? "UNDETERMINED" : database[i].second) << "\n";
        }
    }
}
