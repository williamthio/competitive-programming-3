#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void uva_10172() {
    int set;
    cin >> set;
    while (set--) {
        unsigned int n, sn, qn;
        cin >> n;
        cin >> sn;
        cin >> qn;

        vector<queue<int>> stations(n);
        int cargoLeft = 0;
        for (unsigned int i = 0; i < n; i++) {
            int qi;
            cin >> qi;
            for (int j = 0; j < qi; j++) {
                int dest;
                cin >> dest;
                stations[i].push(dest - 1);
                cargoLeft++;
            }
        }

        int pos = 0;
        int minutesPassed = -2;
        stack<int> carrier;
        while (cargoLeft) {
            minutesPassed += 2;
            while (!carrier.empty()) {
                if (carrier.top() != pos) {
                    if (stations[pos].size() == qn)
                        break;
                    stations[pos].push(carrier.top());
                }
                else {
                    cargoLeft--;
                }
                carrier.pop();
                minutesPassed += 1;
            }
            while (!stations[pos].empty() && carrier.size() < sn) {
                carrier.push(stations[pos].front());
                stations[pos].pop();
                minutesPassed += 1;
            }
            if (++pos == n)
                pos = 0;
        }

        cout << minutesPassed << "\n";
    }
}
