#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void uva_11995() {
    int n;
    while (cin >> n, !cin.fail()) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool isStack = true;
        bool isQueue = true;
        bool isPriorityQueue = true;

        while (n--) {
            int cmd, value;
            cin >> cmd;
            cin >> value;
            if (cmd == 1) {
                if (isStack)
                    s.push(value);
                if (isQueue)
                    q.push(value);
                if (isPriorityQueue)
                    pq.push(value);
            }
            else {
                if (s.empty() || s.top() != value)
                    isStack = false;
                else if (isStack)
                    s.pop();

                if (q.empty() || q.front() != value)
                    isQueue = false;
                else if (isQueue)
                    q.pop();

                if (pq.empty() || pq.top() != value)
                    isPriorityQueue = false;
                else if (isPriorityQueue)
                    pq.pop();
            }
        }

        int count = (isStack ? 1 : 0) + (isQueue ? 1 : 0) + (isPriorityQueue ? 1 : 0);
        if (count > 1)
            cout << "not sure\n";
        else if (isStack)
            cout << "stack\n";
        else if (isQueue)
            cout << "queue\n";
        else if (isPriorityQueue)
            cout << "priority queue\n";
        else
            cout << "impossible\n";
    }
}
