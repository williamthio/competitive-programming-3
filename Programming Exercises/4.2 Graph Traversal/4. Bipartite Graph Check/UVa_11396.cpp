#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

void uva_11396() {
    int n;
    while (cin >> n, n) {
        vector<vector<int>> adj(n);
        int a, b;
        while (cin >> a, cin >> b, a && b) {
            adj[a - 1].push_back(b - 1);
            adj[b - 1].push_back(a - 1);
        }

        int color[300];
        memset(color, -1, sizeof color);
        queue<int> q;
        q.push(0);
        color[0] = 0;
        bool bipartite = true;

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

        cout << (bipartite ? "YES\n" : "NO\n");
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_11396();
    return 0;
}

