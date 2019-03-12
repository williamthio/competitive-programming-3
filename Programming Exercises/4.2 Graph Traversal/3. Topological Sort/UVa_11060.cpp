#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

void uva_11060() {
    int n;
    int ci = 0;
    while (cin >> n, !cin.fail()) {
        vector<string> beverages(n);
        unordered_map<string, int> index;
        for (int i = 0; i < n; i++) {
            cin >> beverages[i];
            index[beverages[i]] = i;
        }

        int m;
        cin >> m;

        vector<vector<int>> adj(n);
        int incoming[100];
        memset(incoming, 0, sizeof incoming);
        while (m--) {
            string a, b;
            cin >> a;
            cin >> b;
            int ib = index[b];
            adj[index[a]].push_back(ib);
            incoming[ib]++;
        }

        priority_queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!incoming[i])
                q.push(-i);
        }

        vector<int> l;
        while (!q.empty()) {
            int u = -q.top();
            q.pop();
            l.push_back(u);
            for (int v : adj[u]) {
                incoming[v]--;
                if (!incoming[v])
                    q.push(-v);
            }
        }

        cout << "Case #" << ++ci << ": Dilbert should drink beverages in this order:";
        for (auto it = l.begin(); it != l.end(); it++) {
            cout << " " << beverages[*it];
        }
        cout << ".\n\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_11060();
    return 0;
}

