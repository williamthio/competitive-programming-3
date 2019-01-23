#include <iostream>

using namespace std;

void e_2_2_2() {
    auto no1 = [&]() {
        int s = 31;
        int n = 16;
        int mod = s & (n - 1);
        cout << mod;
    };

    auto no2 = [&]() {
        int s = 8;
        cout << ((s << 1) == 2 * s);
    };

    auto no3 = [&]() {
        int s = 40;
        cout << (s & ~(s & (-s)));
    };

    auto no4 = [&]() {
        int s = 41;
        cout << (s | (~s & (-(~s))));
    };

    auto no5 = [&]() {
        int s = 39;
        cout << (s & ~((~s & (-(~s))) - 1));
    };

    auto no6 = [&]() {
        int s = 36;
        cout << (s | ((s & (-s)) - 1));
    };

    auto no7 = [&]() {
        // UVa - 11173
        int tc, n, k;
        cin >> tc;
        while (tc--) {
            cin >> n;
            cin >> k;
            int out = 0;
            // TLE
            //for (int i = 0; i < k; i++)
            //    out = out ^ (~i & (i + 1));
            int low = 0;
            int high = (1 << n) - 1;
            bool flip = false;
            while (n--) {
                int mid = (low + high) / 2;
                if (!flip && k > mid || flip && k <= mid)
                    out |= 1 << n;
                if (k > mid) {
                    low = mid + 1;
                    flip = true;
                }
                else {
                    high = mid;
                    flip = false;
                }
            }
            cout << out << "\n";
        }
    };

    no7();
}
