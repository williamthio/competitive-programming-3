#include <iostream>
#include <cstring>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void uva_00872() {
    int tc;
    cin >> tc;
    cin.get();
    bool start = true;
    while (tc--) {
        if (!start)
            cout << "\n";
        start = false;

        cin.get();
        string line;
        getline(cin, line);

        vector<int> variables;
        for (int i = 0, n = line.size(); i < n; i += 2)
            variables.push_back(line[i] - 'A');
        sort(variables.begin(), variables.end());

        int index[26];
        int adj[20][51];
        for (int i = 0; i < (int)variables.size(); i++) {
            adj[i][0] = 0;
            index[variables[i]] = i;
        }

        getline(cin, line);
        for (int i = 0; i < (int)line.size(); i += 4) {
            int a = line[i] - 'A';
            int b = line[i + 2] - 'A';
            adj[index[b]][++adj[index[b]][0]] = index[a];
        }

        int visited[20];
        memset(visited, 0, sizeof visited);

        bool cycle = false;
        function<void(int)> dfs = [&](int v) {
            if (visited[v] == 1)
                return;
            if (visited[v] == -1) {
                cycle = true;
                return;
            }
            visited[v] = -1;
            for (int i = 1; !cycle && i <= adj[v][0]; i++)
                dfs(adj[v][i]);
            visited[v] = 1;
        };

        for (int i = 0; i < (int)variables.size(); i++) {
            dfs(i);
            if (cycle)
                break;
        }

        if (cycle) {
            cout << "NO\n";
            continue;
        }

        char output[40];
        memset(output, ' ', sizeof output);
        output[variables.size() * 2 - 1] = '\0';

        function<void(int, int)> generate = [&](int mask, int pos) {
            if (pos == variables.size()) {
                cout << output << "\n";
                return;
            }
            for (int i = 0; i < (int)variables.size(); i++) {
                if (mask & (1 << i))
                    continue;
                bool valid = true;
                for (int j = 1; j <= adj[i][0]; j++) {
                    if (!(mask & (1 << adj[i][j]))) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    output[pos * 2] = variables[i] + 'A';
                    generate(mask | (1 << i), pos + 1);
                }
            }
        };

        generate(0, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_00872();
    return 0;
}

