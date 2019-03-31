#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstring>
#include <stack>
#include <functional>

using namespace std;

void uva_00247() {
    int n, m;
    int ci = 0;
    while (cin >> n, cin >> m, n || m) {
        if (ci > 0)
            cout << "\n";
        cout << "Calling circles for data set " << ++ci << ":\n";

        if (!m)
            continue;

        vector<vector<int>> adj(n);
        vector<string> names;
        unordered_map<string, int> index;
        unordered_map<string, bool> added;
        while (m--) {
            string a, b;
            cin >> a;
            cin >> b;
            if (!added[a]) {
                added[a] = true;
                index[a] = names.size();
                names.push_back(a);
            }
            if (!added[b]) {
                added[b] = true;
                index[b] = names.size();
                names.push_back(b);
            }
            adj[index[a]].push_back(index[b]);
        }

        int count = 0;
        int num[25], low[25];
        memset(num, -1, sizeof num);
        bool visited[25];
        memset(visited, false, sizeof visited);
        stack<int> s;

        function<void(int)> tarjanScc = [&](int u) {
            num[u] = low[u] = count++;
            s.push(u);
            visited[u] = true;
            for (int v : adj[u]) {
                if (num[v] == -1)
                    tarjanScc(v);
                if (visited[v])
                    low[u] = min(low[u], low[v]);
            }
            if (num[u] == low[u]) {
                bool first = true;
                while (!s.empty()) {
                    int v = s.top();
                    s.pop();
                    visited[v] = false;
                    if (!first)
                        cout << ", ";
                    first = false;
                    cout << names[v];
                    if (v == u)
                        break;
                }
                cout << "\n";
            }
        };

        for (int i = 0; i < n; i++) {
            if (num[i] == -1)
                tarjanScc(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_00247();
    return 0;
}

