#include <bits/stdc++.h>

using namespace std;

void uva_11838() {
    int n, m;
    while (cin >> n >> m, n && m) {
        vector<vector<int>> adj(n);
        while (m--) {
            int v, w, p;
            cin >> v >> w >> p;
            adj[v - 1].push_back(w - 1);
            if (p == 2)
                adj[w - 1].push_back(v - 1);
        }
        int counter = 0;
        vector<int> index, lowlink;
        vector<bool> onstack;
        stack<int> s;
        index.assign(n, -1);
        lowlink.assign(n, -1);
        onstack.assign(n, false);
        int scc = 0;
        function<void(int)> strongconnect = [&](int v) {
            index[v] = lowlink[v] = counter++;
            s.push(v);
            onstack[v] = true;
            for (int w : adj[v]) {
                if (index[w] == -1) {
                    strongconnect(w);
                    lowlink[v] = min(lowlink[v], lowlink[w]);
                }
                else if (onstack[w]) {
                    lowlink[v] = min(lowlink[v], index[w]);
                }
            }
            if (lowlink[v] == index[v]) {
                while (true) {
                    int w = s.top();
                    s.pop();
                    onstack[w] = false;
                    if (w == v)
                        break;
                }
                scc++;
            }
        };
        for (int v = 0; v < n; v++) {
            if (index[v] == -1)
                strongconnect(v);
        }
        cout << (scc <= 1) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_11838();
    return 0;
}

