#include <iostream>
#include <functional>
#include <utility>

using namespace std;

void uva_00624() {
    int n;
    while (cin >> n, !cin.fail()) {
        int tn, tracks[20];
        cin >> tn;

        for (int i = 0; i < tn; i++)
            cin >> tracks[i];

        function<pair<int, int>(int, int, int)> find =
            [&](int start, int selected, int sum) {
            pair<int, int> max;
            for (int i = start + 1; i < tn; i++) {
                if (sum + tracks[i] > n)
                    continue;
                pair<int, int> result = find(i, selected | (1 << i), sum + tracks[i]);
                if (max.second < result.second)
                    max = result;
            }
            if (max.second > sum)
                return max;
            return make_pair(selected, sum);
        };

        pair<int, int> result = find(-1, 0, 0);
        for (int i = 0; i < tn; i++) {
            if (result.first & (1 << i))
                cout << tracks[i] << " ";
        }
        cout << "sum:" << result.second << "\n";
    }
}
