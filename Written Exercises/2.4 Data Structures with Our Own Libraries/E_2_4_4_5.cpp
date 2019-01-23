#include <iostream>
#include <vector>
#include <limits>
#include <functional>

using namespace std;

void e_2_4_4_5() {
    int n, tc = 0;
    bool start = true;
    while (cin >> n, n) {
        if (!start)
            cout << "\n";
        start = false;
        cout << "Case " << ++tc << ":\n";

        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        vector<int> tree = arr;
        for (int i = 1; i <= n; i++) {
            int j = i + (i & -i);
            if (j <= n)
                tree[j] += tree[i];
        }

        auto update = [&](int i, int diff) {
            while (i <= n) {
                tree[i] += diff;
                i += (i & -i);
            }
        };

        auto read = [&](int i) {
            int sum = 0;
            while (i > 0) {
                sum += tree[i];
                i -= (i & -i);
            }
            return sum;
        };

        char cmd;
        while (cin >> cmd, cmd != 'E') {
            int a, b;
            cin >> a;
            cin >> b;
            if (cmd == 'S') {
                update(a, b - arr[a]);
                arr[a] = b;
            }
            else if (cmd == 'M')
                cout << read(b) - read(a - 1) << "\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
