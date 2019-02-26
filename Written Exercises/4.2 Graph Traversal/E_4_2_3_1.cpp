#include <iostream>
#include <functional>
#include <cstring>
#include <unordered_map>
#include <string>
#include <utility>

using namespace std;

void e_4_2_3_1() {
    int tc;
    cin >> tc;
    cin.get();
    cin.get();

    bool start = true;
    while (tc--) {
        string line;
        getline(cin, line);
        int maxNode = line[0] - 'A';

        int edges[26][27];
        for (int i = 0; i <= maxNode; i++)
            edges[i][0] = 0;

        unordered_map<string, bool> inserted;
        while (getline(cin, line), !line.empty()) {
            if (line[0] > line[1])
                swap(line[0], line[1]);
            if (inserted[line])
                continue;
            inserted[line] = true;
            int a = line[0] - 'A';
            int b = line[1] - 'A';
            edges[a][++edges[a][0]] = b;
            edges[b][++edges[b][0]] = a;
        }

        bool visited[26];
        memset(visited, false, sizeof visited);

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (int i = 1; i <= edges[node][0]; i++) {
                if (!visited[edges[node][i]])
                    dfs(edges[node][i]);
            }
        };

        int count = 0;
        for (int node = 0; node <= maxNode; node++) {
            if (visited[node])
                continue;
            dfs(node);
            count++;
        }

        if (!start)
            cout << "\n";
        start = false;
        cout << count << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    e_4_2_3_1();
    return 0;
}

