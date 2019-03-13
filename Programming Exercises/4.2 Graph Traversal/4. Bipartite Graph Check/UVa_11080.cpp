#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <functional>

using namespace std;

void uva_11080() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, e;
        cin >> n;
        cin >> e;

        vector<vector<int>> adj(n);
        while (e--) {
            int a, b;
            cin >> a;
            cin >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int color[200];
        memset(color, -1, sizeof color);
        int blackCount, whiteCount;
        bool bipartite = true;

        function<void(int)> bfs = [&](int s) {
            queue<int> q;
            q.push(s);
            color[s] = 0;
            blackCount++;
            while (!q.empty() && bipartite) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        if (color[v])
                            whiteCount++;
                        else
                            blackCount++;
                        q.push(v);
                    }
                    else if (color[v] == color[u]) {
                        bipartite = false;
                        break;
                    }
                }
            }
        };

        int count = 0;

        for (int i = 0; i < n && bipartite; i++) {
            if (!adj[i].size()) {
                count++;
            }
            else if (color[i] == -1) {
                blackCount = whiteCount = 0;
                bfs(i);
                count += min(blackCount, whiteCount);
            }
        }

        if (bipartite) {
            cout << count << "\n";
        }
        else {
            cout << "-1\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_11080();
    return 0;
}

