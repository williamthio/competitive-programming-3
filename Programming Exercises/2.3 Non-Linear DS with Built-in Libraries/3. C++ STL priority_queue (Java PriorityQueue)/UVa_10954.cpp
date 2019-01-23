#include <iostream>
#include <queue>

using namespace std;

void uva_10954() {
    priority_queue<int> q;
    int n;
    while (cin >> n, n) {
        while (n--) {
            int num;
            cin >> num;
            q.push(-num);
        }

        long long total = 0;
        while (q.size() > 1) {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            total += a + b;
            q.push(a + b);
        }
        q.pop();

        cout << -total << "\n";
    }
}
