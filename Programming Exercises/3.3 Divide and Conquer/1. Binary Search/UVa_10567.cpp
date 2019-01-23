#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <functional>

using namespace std;

void uva_10567() {
    string s;
    cin >> s;

    vector<int> states[52];
    auto stateIdx = [&](char c) {
        return islower(c) ? c - 'a' : c - 'A' + 26;
    };
    for (int i = 0, n = s.size(); i < n; i++)
        states[stateIdx(s[i])].push_back(i);

    auto search = [&](char c, int min) -> int {
        int si = stateIdx(c);
        int idx = -1;
        int left = 0;
        int right = states[si].size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (states[si][mid] >= min) {
                idx = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return idx;
    };

    int q;
    cin >> q;
    while (q--) {
        string ss;
        cin >> ss;
        bool mismatch = false;
        int min = -1;
        int curr = -1;
        for (char c : ss) {
            int idx = search(c, curr + 1);
            if (idx == -1) {
                mismatch = true;
                break;
            }

            curr = states[stateIdx(c)][idx];

            if (min == -1)
                min = curr;
        }

        if (mismatch)
            cout << "Not matched\n";
        else
            cout << "Matched " << min << " " << curr << "\n";
    }
}
