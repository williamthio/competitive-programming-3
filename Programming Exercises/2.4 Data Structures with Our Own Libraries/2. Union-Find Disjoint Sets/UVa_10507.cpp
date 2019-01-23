#include <iostream>
#include <cctype>
#include <functional>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <utility>
#include <limits>

using namespace std;

void uva_10507() {
    int n;
    while (cin >> n, !cin.fail()) {
        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int activeAreas = 0;
        auto setActive = [&](char c) {
            activeAreas |= 1 << (c - 'A');
        };
        auto isActive = [&](char c) -> bool {
            return (activeAreas & (1 << (c - 'A'))) != 0;
        };

        int activeCount = 0;
        char c;
        while (c = cin.get(), !cin.fail() && isupper(c)) {
            setActive(c);
            activeCount++;
        }

        int weights[26] = { 0 };
        unordered_map<int, vector<int>> adjacencyList;
        unordered_map<string, bool> edgeExists;
        string edge;
        while (m--) {
            cin >> edge;
            if (edge.size() != 2 || !isupper(edge[0]) || !isupper(edge[1]) || edge[0] == edge[1])
                continue;
            if (edge[0] > edge[1])
                swap(edge[0], edge[1]);
            if (isActive(edge[0]) && isActive(edge[1]))
                continue;
            if (edgeExists[edge])
                continue;
            edgeExists[edge] = true;

            int a = edge[0] - 'A';
            int b = edge[1] - 'A';
            if (isActive(edge[0]))
                weights[b]++;
            else if (isActive(edge[1]))
                weights[a]++;
            else {
                adjacencyList[a].push_back(b);
                adjacencyList[b].push_back(a);
            }
        }

        int years = 0;
        while (true) {
            priority_queue<pair<int, int>> q;
            for (int i = 0; i < 26; i++) {
                if (weights[i] > 0)
                    q.push(make_pair(weights[i], i));
            }
            if (q.empty() || q.top().first < 3)
                break;
            while (!q.empty() && q.top().first >= 3) {
                char ci = q.top().second;
                setActive(ci + 'A');
                weights[ci] = 0;
                for (char adj : adjacencyList[ci]) {
                    if (!isActive(adj + 'A'))
                        weights[adj]++;
                }
                q.pop();
            }
            years++;
        }

        for (auto it = adjacencyList.begin(); it != adjacencyList.end(); it++) {
            if (isActive(it->first + 'A')) {
                activeCount++;
            }
        }

        if (activeCount < n)
            cout << "THIS BRAIN NEVER WAKES UP\n";
        else
            cout << "WAKE UP IN, " << years << ", YEARS\n";
    }
}
