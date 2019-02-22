#include <iostream>
#include <queue>
#include <functional>
#include <cstring>
#include <string>

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

        bool relationships[100][100];
        memset(relationships, true, sizeof relationships);

        queue<int> q;
        bool visited[100];
        memset(visited, false, sizeof visited);

        for (int i = 0; i < n; i++) {
            relationships[0][i] = false;
            relationships[i][i] = false;
            relationships[i][0] = false;
        }

        q.push(0);
        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            visited[idx] = true;
            relationships[0][idx] = true;
            relationships[idx][idx] = true;
            for (int j = 1; j <= edges[idx][0]; j++) {
                if (!visited[edges[idx][j]])
                    q.push(edges[idx][j]);
            }
        }

        for (int x = 1; x < n; x++) {
            if (!relationships[x][x]) {
                for (int j = 1; j < n; j++) {
                    relationships[j][x] = false;
                    relationships[x][j] = false;
                }
                continue;
            }
            memset(visited, false, sizeof visited);
            queue<int> qu;
            qu.push(0);
            while (!qu.empty()) {
                int idx = qu.front();
                qu.pop();
                visited[idx] = true;
                if (idx == x)
                    continue;
                relationships[x][idx] = false;
                for (int j = 1; j <= edges[idx][0]; j++) {
                    if (!visited[edges[idx][j]])
                        qu.push(edges[idx][j]);
                }
            }
        }

        function<void()> printSeparator = [&]() {
            cout << "+";
            for (int i = 0; i < n; i++) {
                if (i == n - 1)
                    cout << "-+\n";
                else
                    cout << "--";
            }
        };

        cout << "Case " << ci << ":\n";
        printSeparator();
        for (int i = 0; i < n; i++) {
            cout << "|";
            for (int j = 0; j < n; j++)
                cout << (relationships[i][j] == 1 ? "Y|" : "N|");
            cout << "\n";
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

