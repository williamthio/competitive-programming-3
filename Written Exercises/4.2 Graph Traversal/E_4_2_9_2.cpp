#include <iostream>
#include <functional>
#include <cstring>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

void e_4_2_9_2() {
    int v = 11;
    vector<int> adj[v];
    adj[0] = { 1, 8 };
    adj[1] = { 3 };
    adj[2] = { 1 };
    adj[3] = { 2, 4 };
    adj[4] = { 5 };
    adj[5] = { 7 };
    adj[6] = { 4 };
    adj[7] = { 6 };
    adj[8] = { 9 };
    adj[9] = { 10 };
    adj[10] = { 8 };

    vector<int> num, low;
    vector<bool> visited;
    stack<int> s;
    int numCounter;

    unordered_map<int, vector<int>> dagAdj, sccArr;
    vector<int> children;

    function<void(int)> tarjanScc = [&](int u) {
        low[u] = num[u] = numCounter++;
        s.push(u);
        visited[u] = true;

        for (int i = 0, n = adj[u].size(); i < n; i++) {
            int v = adj[u][i];
            if (num[v] == -1)
                tarjanScc(v);
            if (visited[v])
                low[u] = min(low[u], low[v]);
        }

        if (low[u] == num[u]) {
            while (true) {
                int v = s.top();
                s.pop();
                visited[v] = false;
                sccArr[num[u]].push_back(v);
                if (u == v)
                    break;
            }

            if (!s.empty())
                dagAdj[low[s.top()]].push_back(num[u]);
        }
    };

    num.assign(v, -1);
    low.assign(v, 0);
    visited.assign(v, false);
    numCounter = 0;
    for (int i = 0; i < v; i++) {
        if (num[i] == -1)
            tarjanScc(i);
    }

    for (auto p: sccArr) {
        cout << "SCC " << p.first << ":";
        for (int j : p.second)
            cout << " " << j;
        cout << "\n";
    }

    for (auto p : dagAdj) {
        cout << p.first << " ->";
        for (int i : p.second)
            cout << " " << i;
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    e_4_2_9_2();
    return 0;
}

