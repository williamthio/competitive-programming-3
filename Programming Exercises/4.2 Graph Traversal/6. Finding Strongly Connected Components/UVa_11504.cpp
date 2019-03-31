#include <iostream>
#include <vector>
#include <cstring>
#include <functional>
#include <algorithm>

using namespace std;

void uva_11504() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n;
        cin >> m;

        vector<vector<int>> adj(n);
        while (m--) {
            int a, b;
            cin >> a;
            cin >> b;
            adj[a - 1].push_back(b - 1);
        }

        bool visited[100000];

        function<int(int)> dfs = [&](int u) {
            if (visited[u])
                return 0;
            visited[u] = true;
            int sum = 1;
            for (int v : adj[u])
                sum += dfs(v);
            return sum;
        };

        vector<pair<int, int>> nodes;

        for (int i = 0; i < n; i++) {
            memset(visited, false, sizeof visited);
            nodes.push_back(make_pair(-dfs(i), i));
        }

        sort(nodes.begin(), nodes.end());
        memset(visited, false, sizeof visited);

        int count = 0;
        for (pair<int, int> p : nodes) {
            if (dfs(p.second))
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

