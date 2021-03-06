#include <bits/stdc++.h>

using namespace std;

void uva_11504() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n);
        while (m--) {
            int a, b;
            cin >> a >> b;
            adj[a - 1].push_back(b - 1);
        }

        int counter = 0;
        stack<int> s;
        vector<int> index, lowlink, sccparent;
        vector<bool> onstack;
        unordered_map<int, bool> knocked;
        index.assign(n, -1);
        lowlink.assign(n, -1);
        sccparent.assign(n, -1);
        onstack.assign(n, false);

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
                    sccparent[w] = v;
                    if (w == v)
                        break;
                }
                knocked[v] = false;
            }
        };

        for (int v = 0; v < n; v++) {
            if (index[v] == -1)
                strongconnect(v);
        }

        for (int i = 0; i < (int)adj.size(); i++) {
            for (int j = 0; j < (int)adj[i].size(); j++) {
                //cout << i + 1 << "(" << sccparent[i] << ")" << " - " << adj[i][j] + 1 << "(" << sccparent[adj[i][j]] << ") ";
                if (sccparent[i] != sccparent[adj[i][j]])
                    knocked[sccparent[adj[i][j]]] = true;
                //cout << knocked[sccparent[adj[i][j]]] << "\n";
            }
        }

        //for (int i = 0; i < n; i++)
        //    cout << i + 1 << " -> " << sccparent[i] << "\n";

        int count = 0;
        for (auto it = knocked.begin(); it != knocked.end(); it++) {
            //cout << it->first << "\n";
            if (!it->second)
                count++;
        }
        cout << count << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_11504();
    return 0;
}

