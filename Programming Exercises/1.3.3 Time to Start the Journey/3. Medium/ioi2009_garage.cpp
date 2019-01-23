#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;

void ioi2009_garage() {
    int n, m, i, j, car, prev, cp, parked = 0, total = 0;
    vector<int> rates, weights;
    bitset<100> spaces;
    unordered_map<int, int> carPosition;
    queue<int> q;
    cin >> n;
    cin >> m;
    rates.resize(n);
    weights.resize(m);
    for (i = 0; i < n; i++)
        cin >> rates[i];
    for (i = 0; i < m; i++)
        cin >> weights[i];
    for (i = 0; i < 2 * m; i++) {
        cin >> car;
        prev = 0;
        if (car < 0) {
            cp = carPosition[car * -1 - 1];
            if (parked == n)
                prev = cp;
            parked--;
            spaces[cp] = 0;
        }
        else if (car > 0) {
            q.push(car - 1);
        }
        for (j = prev; j < n && !q.empty() && parked < n; j++) {
            if (!spaces[j]) {
                spaces[j] = 1;
                parked++;
                carPosition[q.front()] = j;
                total += rates[j] * weights[q.front()];
                q.pop();
            }
        }
    }
    cout << total;
}
