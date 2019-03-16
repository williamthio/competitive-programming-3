#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <utility>
#include <unordered_set>
#include <cstring>

using namespace std;

void uva_10765() {
    int n, m;
    while (cin >> n, cin >> m, n || m) {
        vector<vector<int>> adj(n);
        int a, b;
        while (cin >> a, cin >> b, a != -1 && b != -1) {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int num[10000];
        int low[10000];
        int parent[10000];
        int count = 0;
        int root, rootChildren;
        unordered_set<int> ap;
        memset(num, -1, sizeof num);

        function<void(int)> dfs = [&](int u) {
            num[u] = low[u] = count++;
            for (int v : adj[u]) {
                if (num[v] == -1) {
                    parent[v] = u;
                    dfs(v);
                    if (u == root)
                        rootChildren++;
                    else if (low[v] >= num[u])
                        ap.insert(u);
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
            root = i;
            rootChildren = 0;
            dfs(i);
            if (rootChildren > 1)
                ap.insert(i);
        }

        bool visited[10000];
        int block;
        function<void(int)> check = [&](int u) {
            visited[u] = true;
            if (u == block)
                return;
            for (int v : adj[u]) {
                if (!visited[v])
                    check(v);
            }
        };

        vector<pair<int, int>> values;
        bool inserted[10000];
        memset(inserted, false, sizeof inserted);
        for (int i : ap) {
            block = i;
            int cc = 0;
            memset(visited, false, sizeof visited);
            for (int j = 0; j < n; j++) {
                if (visited[j] || j == block)
                    continue;
                cc++;
                check(j);
            }
            values.push_back(make_pair(-cc, i));
            inserted[i] = true;
        }

        int idx = 0;
        while (values.size() < m) {
            while (inserted[idx])
                idx++;
            inserted[idx] = true;
            values.push_back(make_pair(-1, idx));
        }

        partial_sort(values.begin(), values.begin() + m, values.end());
        for (int i = 0; i < m; i++)
            cout << values[i].second << " " << -values[i].first << "\n";
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_10765();
    return 0;
}

