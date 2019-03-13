#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

void uva_10004() {
    int n;
    while (cin >> n, n) {
        int m;
        cin >> m;

        vector<vector<int>> adj(n);
        while (m--) {
            int a, b;
            cin >> a;
            cin >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        bool bipartite = true;

        int color[199];
        memset(color, -1, sizeof color);
        color[0] = 0;

        queue<int> q;
        q.push(0);

        while (!q.empty() && bipartite) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    bipartite = false;
                    break;
                }
            }
        }

        if (!bipartite)
            cout << "NOT ";
        cout << "BICOLORABLE.\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_10004();
    return 0;
}

