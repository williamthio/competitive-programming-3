#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <utility>

using namespace std;

void uva_00796() {
    int n;
    while (cin >> n, !cin.fail()) {
        vector<vector<int>> adj(n);
        int u;
        for (int i = 0; i < n; i++) {
            cin >> u;
            cin.get();
            cin.get();
            int m;
            cin >> m;
            cin.get();
            while (m--) {
                int v;
                cin >> v;
                adj[u].push_back(v);
            }
        }

        vector<int> num, low, parent;
        num.assign(n, -1);
        low.assign(n, 0);
        parent.assign(n, -1);
        int count = 0;
        vector<pair<int, int>> bridges;

        function<void(int)> dfs = [&](int u) {
            num[u] = low[u] = count++;
            for (int v : adj[u]) {
                if (num[v] == -1) {
                    parent[v] = u;
                    dfs(v);
                    if (low[v] > num[u]) {
                        if (u < v)
                            bridges.push_back(make_pair(u, v));
                        else
                            bridges.push_back(make_pair(v, u));
                    }
                    low[u] = min(low[u], low[v]);
                }
                else if (parent[u] != v) {
                    low[u] = min(low[u], num[v]);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (num[i] != -1)
                continue;
            dfs(i);
        }

        cout << bridges.size() << " critical links\n";
        sort(bridges.begin(), bridges.end());
        for (auto bridge : bridges)
            cout << bridge.first << " - " << bridge.second << "\n";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_00796();
    return 0;
}

