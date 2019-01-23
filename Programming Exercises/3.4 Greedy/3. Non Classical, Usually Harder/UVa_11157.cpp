#include <iostream>
#include <functional>

using namespace std;

void uva_11157() {
    int tc;
    cin >> tc;
    for (int ci = 1; ci <= tc; ci++) {
        int n, d;
        cin >> n;
        cin >> d;

        int rocks[101], rn = 0;
        int softs[101], sn = 0;
        int prevBig = 0;

        auto getMax = [&](int last) {
            if (sn > 1) {
                int i;
                int maxEven = softs[0] - prevBig;
                for (i = 2; i < sn; i += 2) {
                    int distance = softs[i] - softs[i - 2];
                    if (maxEven < distance)
                        maxEven = distance;
                }
                if (maxEven < last - softs[i - 2])
                    maxEven = last - softs[i - 2];

                int maxOdd = softs[1] - prevBig;
                for (i = 3; i < sn; i += 2) {
                    int distance = softs[i] - softs[i - 2];
                    if (maxOdd < distance)
                        maxOdd = distance;
                }
                if (maxOdd < last - softs[i - 2])
                    maxOdd = last - softs[i - 2];

                for (int i = maxEven > maxOdd ? 0 : 1; i < sn; i += 2)
                    rocks[rn++] = softs[i];
            }
        };

        for (int i = 0; i < n; i++) {
            char type, dash;
            int rock;
            cin >> type;
            cin >> dash;
            cin >> rock;
            if (type == 'B') {
                getMax(rock);
                sn = 0;
                prevBig = rock;
                rocks[rn++] = rock;
            }
            else {
                softs[sn++] = rock;
            }
        }
        getMax(d);
        rocks[rn++] = d;

        int max = rocks[0];
        for (int i = 1; i < rn; i++) {
            int distance = rocks[i] - rocks[i - 1];
            if (max < distance)
                max = distance;
        }

        cout << "Case " << ci << ": " << max << "\n";
    }
}
