#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void uva_00481() {
    vector<int> arr;
    int num;
    while (cin >> num, !cin.fail())
        arr.push_back(num);

    vector<int> parents(arr.size());

    vector<int> lis, lisIdx;
    for (int i = 0, n = arr.size(); i < n; i++) {
        int low = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
        parents[i] = low == 0 ? -1 : lisIdx[low - 1];
        if (low == lis.size()) {
            lis.push_back(arr[i]);
            lisIdx.push_back(i);
        }
        else {
            lis[low] = arr[i];
            lisIdx[low] = i;
        }
    }

    stack<int> out;
    int idx = *lisIdx.rbegin();
    while (idx != -1) {
        out.push(arr[idx]);
        idx = parents[idx];
    }

    cout << out.size() << "\n-\n";
    while (!out.empty()) {
        cout << out.top() << "\n";
        out.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_00481();
    return 0;
}

