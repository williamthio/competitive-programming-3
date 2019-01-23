#include <iostream>
#include <utility>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

void uva_01047() {
    auto choose = [&](int n, int k) {
        if (k > n)
            return 0;
        int r = 1;
        for (int d = 1; d <= k; d++) {
            r *= n--;
            r /= d;
        }
        return r;
    };

    int n, k, ci = 0;
    while (cin >> n, cin >> k, n || k) {
        int served[20];
        for (int i = 0; i < n; i++)
            cin >> served[i];

        vector<pair<vector<int>, int>> csa;
        int m;
        cin >> m;
        while (m--) {
            int t;
            cin >> t;

            vector<int> towers(t);
            for (int i = 0; i < t; i++)
                cin >> towers[i];
            sort(towers.begin(), towers.end());

            int cn;
            cin >> cn;
            csa.push_back(make_pair(towers, cn));
        }

        function<pair<int, vector<int>>(int, int, vector<int>)> getMax =
            [&](int start, int sum, vector<int> arr) -> pair<int, vector<int>> {
            if (arr.size() == k) {
                for (auto area : csa) {
                    int count = 0;
                    for (int i : arr) {
                        if (binary_search(area.first.begin(), area.first.end(), i + 1))
                            count++;
                    }
                    for (int i = 2; i <= count; i++)
                        sum += area.second * choose(count, i) * (i % 2 ? 1 : -1);
                }
                return make_pair(sum, arr);
            }

            pair<int, vector<int>> max;
            for (int i = start + 1, an = arr.size(); i < n - (k - an - 1); i++) {
                int value = sum + served[i];

                arr.push_back(i);
                pair<int, vector<int>> result = getMax(i, value, arr);
                arr.pop_back();

                if (max.first < result.first)
                    max = result;
            }

            return max;
        };

        pair<int, vector<int>> result = getMax(-1, 0, {});
        cout << "Case Number  " << ++ci;
        cout << "\nNumber of Customers: " << result.first;
        cout << "\nLocations recommended: ";
        for (int i = 0, an = result.second.size(); i < an; i++) {
            if (i > 0)
                cout << " ";
            cout << result.second[i] + 1;
        }
        cout << "\n\n";
    }
}
