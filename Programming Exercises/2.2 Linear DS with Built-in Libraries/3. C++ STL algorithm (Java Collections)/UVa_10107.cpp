#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;

void uva_10107() {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    long long median = 0;
    int num;
    while (cin >> num, !cin.fail()) {
        int maxSize = maxHeap.size();
        int minSize = minHeap.size();

        if (num > median) {
            minHeap.push(num);
            minSize += 1;
        }
        else {
            maxHeap.push(num);
            maxSize += 1;
        }

        if (abs(minSize - maxSize) >= 2) {
            if (minSize > maxSize) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            maxSize = maxHeap.size();
            minSize = minHeap.size();
        }

        if (maxSize > minSize)
            median = maxHeap.top();
        else if (maxSize < minSize)
            median = minHeap.top();
        else
            median = ((long long)maxHeap.top() + minHeap.top()) / 2;

        cout << median << "\n";
    }
}
