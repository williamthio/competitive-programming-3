#include <iostream>
#include <cstring>
#include <functional>

using namespace std;

void uva_12442() {
    int tc;
    cin >> tc;
    for (int ci = 1; ci <= tc; ci++) {
        int n;
        cin >> n;

        int adj[50001];
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u;
            cin >> v;
            adj[u] = v;
        }

        int memo[50001];
        memset(memo, 0, sizeof memo);
        int visited[50001];
        memset(visited, 0, sizeof visited);

        int parent;
        int head;
        int count;

        function<void(int)> dfs = [&](int u) {
            visited[u] = parent;
            memo[u] = ++count;

            if (memo[adj[u]]) {
                if (visited[u] == visited[adj[u]])
                    head = adj[u];
            }
            else {
                dfs(adj[u]);
            }
            
            if (head) {
                memo[u] = count - memo[head] + 1;
                if (head == u)
                    head = 0;
            }
            else {
                memo[u] = 1 + memo[adj[u]];
            }
        };

        int from;
        int maxCount = 0;
        for (int i = 1; i <= n; i++) {
            parent = i;
            count = 0;
            head = 0;
            if (!memo[i])
                dfs(i);
            if (maxCount < memo[i]) {
                from = i;
                maxCount = memo[i];
            }
        }

        cout << "Case " << ci << ": " << from << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_12442();
    return 0;
}

