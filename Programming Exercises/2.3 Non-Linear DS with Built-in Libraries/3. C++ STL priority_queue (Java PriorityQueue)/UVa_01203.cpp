#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <unordered_map>

using namespace std;

void uva_01203() {
    unordered_map<int, int> intervals;
    priority_queue<pair<int, int>> q;
    string cmd;
    while (cin >> cmd, cmd.compare("#") != 0) {
        int qnum, interval;
        cin >> qnum;
        cin >> interval;
        intervals[qnum] = interval;
        q.push(make_pair(-interval, -qnum));
    }
    int k;
    cin >> k;
    while (k-- && !q.empty()) {
        pair<int, int> top = q.top();
        cout << -top.second << "\n";
        q.pop();
        top.first -= intervals[-top.second];
        q.push(top);
    }
}
