#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void uva_00193() {
    int m;
    cin >> m;
    while (m--) {
        int n, k;
        cin >> n;
        cin >> k;

        vector<vector<int>> adjList(n);
        while (k--) {
            int a, b;
            cin >> a;
            cin >> b;
            adjList[a - 1].push_back(b - 1);
            adjList[b - 1].push_back(a - 1);
        }

        bool removed[100] = { false };
        int chosen[100];
        int max = -1;
        int maxChosen[100];

        auto allRemoved = [&]() -> bool {
            for (int i = 0; i < n; i++) {
                if (!removed[i])
                    return false;
            }
            return true;
        };

        function<void(int)> check = [&](int idx) {
            if (allRemoved()) {
                if (max < idx) {
                    max = idx;
                    for (int i = 0; i < max; i++)
                        maxChosen[i] = chosen[i];
                }
            }
            else {
                for (int i = 0; i < n; i++) {
                    if (removed[i])
                        continue;

                    chosen[idx] = i + 1;

                    vector<int> rv;
                    removed[i] = true;
                    for (int v : adjList[i]) {
                        if (!removed[v]) {
                            removed[v] = true;
                            rv.push_back(v);
                        }
                    }

                    check(idx + 1);

                    removed[i] = false;
                    for (int v : rv)
                        removed[v] = false;
                }
            }
        };

        check(0);

        cout << max << "\n";
        for (int i = 0; i < max; i++)
            cout << (i > 0 ? " " : "") << maxChosen[i];
        cout << "\n";
    }
}
