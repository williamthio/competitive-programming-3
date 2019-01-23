#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <functional>
#include <cmath>

using namespace std;

void uva_11402() {
    const int kClear = 1;
    const int kSet = 2;
    const int kInverse = 3;

    int tc;
    cin >> tc;
    for (int ci = 1; ci <= tc; ci++) {
        cout << "Case " << ci << ":\n";

        string pirates = "";
        int m;
        cin >> m;
        while (m--) {
            int t;
            cin >> t;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string line;
            getline(cin, line);
            while (t--)
                pirates += line;
        }

        int n = pirates.size();
        int treeSize = 2 * (1 << (int)ceil(log2(n))) - 1;
        vector<int> tree(treeSize);
        vector<int> lazy(treeSize);

        function<void(int, int, int)> construct = [&](int s, int e, int i) {
            if (s == e) {
                tree[i] = pirates[s] - '0';
                return;
            }
            int mid = s + (e - s) / 2;
            construct(s, mid, i * 2 + 1);
            construct(mid + 1, e, i * 2 + 2);
            tree[i] = tree[i * 2 + 1] + tree[i * 2 + 2];
        };

        construct(0, n - 1, 0);

        auto setLazy = [&](int i, int type) {
            if (type == kInverse) {
                if (lazy[i] == kSet)
                    lazy[i] = kClear;
                else if (lazy[i] == kClear)
                    lazy[i] = kSet;
                else if (lazy[i] == kInverse)
                    lazy[i] = 0;
                else
                    lazy[i] = kInverse;
                return;
            }
            lazy[i] = type;
        };

        auto applyLazy = [&](int s, int e, int i, int type) {
            if (type == kInverse)
                tree[i] = (e - s + 1) - tree[i];
            else if (type == kSet)
                tree[i] = e - s + 1;
            else
                tree[i] = 0;
        };

        function<void(int, int, int, int, int, int)> updateRangeUtil =
            [&](int us, int ue, int diff, int s, int e, int i) {
            if (lazy[i] != 0) {
                applyLazy(s, e, i, lazy[i]);
                if (s != e) {
                    setLazy(i * 2 + 1, lazy[i]);
                    setLazy(i * 2 + 2, lazy[i]);
                }
                lazy[i] = 0;
            }
            if (s > e || s > ue || e < us)
                return;
            if (us <= s && e <= ue) {
                applyLazy(s, e, i, diff);
                if (s != e) {
                    setLazy(i * 2 + 1, diff);
                    setLazy(i * 2 + 2, diff);
                }
                return;
            }
            int mid = s + (e - s) / 2;
            updateRangeUtil(us, ue, diff, s, mid, i * 2 + 1);
            updateRangeUtil(us, ue, diff, mid + 1, e, i * 2 + 2);
            tree[i] = tree[i * 2 + 1] + tree[i * 2 + 2];
        };
        auto updateRange = [&](int s, int e, int diff) {
            updateRangeUtil(s, e, diff, 0, n - 1, 0);
        };

        function<int(int, int, int, int, int)> getSumUtil =
            [&](int qs, int qe, int s, int e, int i) {
            if (lazy[i] != 0) {
                applyLazy(s, e, i, lazy[i]);
                if (s != e) {
                    setLazy(i * 2 + 1, lazy[i]);
                    setLazy(i * 2 + 2, lazy[i]);
                }
                lazy[i] = 0;
            }
            if (s > e || s > qe || e < qs)
                return 0;
            if (qs <= s && e <= qe)
                return tree[i];
            int mid = s + (e - s) / 2;
            return getSumUtil(qs, qe, s, mid, i * 2 + 1) +
                getSumUtil(qs, qe, mid + 1, e, i * 2 + 2);
        };
        auto getSum = [&](int s, int e) -> int {
            return getSumUtil(s, e, 0, n - 1, 0);
        };

        int q;
        cin >> q;
        int qNum = 0;
        while (q--) {
            char cmd;
            int s, e;
            cin >> cmd;
            cin >> s;
            cin >> e;
            if (cmd == 'F')
                updateRange(s, e, kSet);
            else if (cmd == 'E')
                updateRange(s, e, kClear);
            else if (cmd == 'I')
                updateRange(s, e, kInverse);
            else
                cout << "Q" << ++qNum << ": " << getSum(s, e) << "\n";
        }
    }
}
