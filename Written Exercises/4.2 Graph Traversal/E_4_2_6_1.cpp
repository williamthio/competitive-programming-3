#include <iostream>
#include <functional>
#include <cstring>
#include <vector>

using namespace std;

void e_4_2_6_1() {
    int n;
    while (cin >> n, n) {
        int l;
        cin >> l;

        vector<vector<int>> edges(n);
        while (l--) {
            int a, b;
            cin >> a;
            cin >> b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        int colors[200];
        memset(colors, -1, sizeof colors);

        bool isBipartite = true;
        colors[0] = 0;

        function<void(int)> dfs = [&](int node) {
            if (!isBipartite)
                return;
            for (int i : edges[node]) {
                if (colors[i] == -1) {
                    colors[i] = 1 - colors[node];
                    dfs(i);
                }
                else if (colors[i] == colors[node]) {
                    isBipartite = false;
                    break;
                }
            }
        };

        dfs(0);
        cout << (isBipartite ? "" : "NOT ") << "BICOLORABLE.\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    e_4_2_6_1();
    return 0;
}

