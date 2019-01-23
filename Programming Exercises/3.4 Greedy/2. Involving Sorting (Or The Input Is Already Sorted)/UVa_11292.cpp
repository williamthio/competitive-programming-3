#include <iostream>
#include <algorithm>

using namespace std;

void uva_11292() {
    int n, m;
    while (cin >> n, cin >> m, n || m) {
        int heads[20000], knights[20000];
        for (int i = 0; i < n; i++)
            cin >> heads[i];
        for (int i = 0; i < m; i++)
            cin >> knights[i];
        sort(heads, heads + n);
        sort(knights, knights + m);

        int idx = 0;
        bool doomed = false;
        int coins = 0;
        for (int i = 0; i < n; i++) {
            int head = heads[i];
            while (idx < m && head > knights[idx])
                idx++;

            if (idx < m) {
                coins += knights[idx++];
            }
            else {
                doomed = true;
                break;
            }
        }

        if (doomed)
            cout << "Loowater is doomed!\n";
        else
            cout << coins << "\n";
    }
}
