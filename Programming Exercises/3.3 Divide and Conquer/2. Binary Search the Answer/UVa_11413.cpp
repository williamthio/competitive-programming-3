#include <iostream>
#include <functional>

using namespace std;

void uva_11413() {
    int n;
    while (cin >> n, !cin.fail()) {
        int m;
        cin >> m;

        int vessels[1000];
        for (int i = 0; i < n; i++)
            cin >> vessels[i];

        auto overflow = [&](int c) -> bool {
            int count = 1;
            int curr = 0;
            for (int i = 0; i < n; i++) {
                int milk = vessels[i];
                if (milk > c)
                    return true;
                if (curr + milk > c) {
                    if (++count > m)
                        return true;
                    curr = milk;
                }
                else {
                    curr += milk;
                }
            }
            return false;
        };

        int low = 1;
        int high = 0;
        for (int i = 0; i < n; i++)
            high += vessels[i];

        while (low <= high) {
            int mid = (low + high) / 2;
            if (overflow(mid))
                low = mid + 1;
            else
                high = mid - 1;
        }

        cout << low << "\n";
    }
}
