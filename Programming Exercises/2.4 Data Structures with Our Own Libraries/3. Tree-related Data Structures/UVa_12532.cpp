#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void uva_12532() {
    int n;
    while (cin >> n, !cin.fail()) {
        int k;
        cin >> k;

        vector<pair<int, int>> arr(n + 1), tree;
        for (int i = 1; i <= n; i++) {
            int v;
            cin >> v;
            arr[i].first = v == 0 ? 1 : 0;
            arr[i].second = v < 0 ? 1 : 0;
        }

        tree = arr;
        for (int i = 1; i <= n; i++) {
            int j = i + (i & -i);
            if (j <= n) {
                tree[j].first += tree[i].first;
                tree[j].second += tree[i].second;
            }
        }

        auto read = [&](int i) -> pair<int, int> {
            pair<int, int> result;
            while (i > 0) {
                result.first += tree[i].first;
                result.second += tree[i].second;
                i -= (i & -i);
            }
            return result;
        };

        while (k--) {
            char cmd;
            int a, b;
            cin >> cmd;
            cin >> a;
            cin >> b;
            if (cmd == 'C') {
                if (arr[a].first && b == 0 || arr[a].second && b < 0)
                    continue;
                pair<int, int> newValue, diff;
                newValue.first = b == 0 ? 1 : 0;
                newValue.second = b < 0 ? 1 : 0;
                diff = newValue;
                diff.first -= arr[a].first;
                diff.second -= arr[a].second;
                arr[a] = newValue;

                while (a <= n) {
                    tree[a].first += diff.first;
                    tree[a].second += diff.second;
                    a += (a & -a);
                }
            }
            else {
                pair<int, int> start = read(a - 1);
                pair<int, int> end = read(b);
                end.first -= start.first;
                end.second -= start.second;
                if (end.first != 0)
                    cout << "0";
                else if (end.second % 2 != 0)
                    cout << "-";
                else
                    cout << "+";
            }
        }
        cout << "\n";
    }
}
