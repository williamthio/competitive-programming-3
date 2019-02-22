#include <iostream>
#include <queue>
#include <functional>
#include <cstring>

using namespace std;

void e_4_2_2_1() {
    int tc;
    cin >> tc;
    for (int ci = 1; ci <= tc; ci++) {
        int n;
        cin >> n;

        int edges[101][101];

        for (int i = 0; i < n; i++)
            edges[i][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                bool connected;
                cin >> connected;
                if (connected)
                    edges[i][++edges[i][0]] = j;
            }
        }

        bool visited[100];

        function<void(int)> dfs = [&](int idx) {
            visited[idx] = true;
            for (int j = 1; j <= edges[idx][0]; j++) {
                if (!visited[edges[idx][j]])
                    dfs(edges[idx][j]);
            }
        };

        function<void(int)> bfs = [&](int start) {
            queue<int> q;
            q.push(start);
            while (!q.empty()) {
                int idx = q.front();
                q.pop();
                visited[idx] = true;
                for (int j = 1; j <= edges[idx][0]; j++) {
                    if (!visited[edges[idx][j]])
                        q.push(edges[idx][j]);
                }
            }
        };

        function<void()> printSeparator = [&]() {
            cout << "\n+";
            for (int i = 0; i < n; i++) {
                if (i == n - 1)
                    cout << "-+\n";
                else
                    cout << "--";
            }
        };

        cout << "Case " << ci << ":";
        printSeparator();
        
        bool reachable[100];
        memset(visited, false, n);
        bfs(0);
        cout << "|";
        for (int i = 0; i < n; i++) {
            reachable[i] = visited[i];
            cout << (visited[i] ? "Y|" : "N|");
        }
        printSeparator();

        for (int x = 1; x < n; x++) {
            memset(visited, false, n);
            visited[x] = true;
            bfs(0);
            cout << "|";
            for (int i = 0; i < n; i++) {
                if (i == x)
                    cout << (reachable[i] ? "Y|" : "N|");
                else
                    cout << (!visited[i] && reachable[i] ? "Y|" : "N|");
            }
            printSeparator();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    e_4_2_2_1();
    return 0;
}

