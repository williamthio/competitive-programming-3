#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <cstring>

using namespace std;

void uva_00315() {
    int n;
    while (cin >> n, n) {
        vector<vector<int>> adj(n);
        int u, v;
        while (cin >> u, u) {
            while (cin.get() != '\n') {
                cin >> v;
                adj[u - 1].push_back(v - 1);
                adj[v - 1].push_back(u - 1);
            }
        }

        int dfsNum[99];
        int dfsLow[99];
        int parent[99];
        int count = 0;
        int root;
        int rootChildren;
        bool critical[99];
        int criticalCount = 0;
        memset(critical, false, sizeof critical);
        memset(dfsNum, -1, sizeof dfsNum);

        function<void(int)> dfs = [&](int u) {
            dfsNum[u] = dfsLow[u] = count++;
            for (int v : adj[u]) {
                if (dfsNum[v] == -1) {
                    parent[v] = u;
                    dfs(v);
                    if (u == root) {
                        rootChildren++;
                    }
                    else if (dfsLow[v] >= dfsNum[u] && !critical[u]) {
                        critical[u] = true;
                        criticalCount++;
                    }
                    dfsLow[u] = min(dfsLow[u], dfsLow[v]);
                }
                else if (parent[u] != v) {
                    dfsLow[u] = min(dfsLow[u], dfsNum[v]);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (dfsNum[i] != -1)
                continue;
            root = i;
            rootChildren = 0;
            dfs(i);
            if (rootChildren > 1)
                criticalCount++;
        }


        cout << criticalCount << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_00315();
    return 0;
}

