#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void uva_11100() {
    int n;
    bool start = true;
    while (cin >> n, n) {
        if (!start)
            cout << "\n";
        start = false;

        int bags[10000];
        for (int i = 0; i < n; i++)
            cin >> bags[i];
        sort(bags, bags + n);

        int k = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            count++;
            if (i == n - 1 || bags[i] != bags[i + 1]) {
                if (k < count)
                    k = count;
                count = 0;
            }
        }

        vector<vector<int>> cBags(k);
        int idx = 0;
        for (int i = 0; i < n; i++)
            cBags[idx++ % k].push_back(bags[i]);

        cout << k << "\n";
        for (int i = 0; i < k; i++) {
            for (int j = 0, cn = cBags[i].size(); j < cn; j++) {
                if (j > 0)
                    cout << " ";
                cout << cBags[i][j];
            }
            cout << "\n";
        }
    }
}
