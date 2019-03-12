#include <iostream>
#include <vector>
#include <functional>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;

void uva_10305() {
    int n, m;
    while (cin >> n, cin >> m, n || m) {
        vector<vector<int>> adj(n);
        while (m--) {
            int a, b;
            cin >> a;
            cin >> b;
            adj[a - 1].push_back(b - 1);
        }

        bool visited[100];
        memset(visited, false, sizeof visited);

        vector<int> order;

        function<void(int)> dfs = [&](int u) {
            if (visited[u])
                return;
            visited[u] = true;
            for (int v : adj[u])
                dfs(v);
            order.push_back(u);
        };

        for (int i = 0; i < n; i++)
            dfs(i);

        for (auto it = order.rbegin(); it != order.rend(); it++) {
            if (it != order.rbegin())
                cout << " ";
            cout << *it + 1;
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_10305();
    return 0;
}

