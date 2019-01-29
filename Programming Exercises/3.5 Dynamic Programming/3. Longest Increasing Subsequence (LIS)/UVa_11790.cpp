#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void uva_11790() {
    int tc;
    cin >> tc;
    for (int ci = 1; ci <= tc; ci++) {
        int n;
        cin >> n;

        vector<int> heights(n);
        for (int i = 0; i < n; i++)
            cin >> heights[i];

        vector<int> widths(n);
        for (int i = 0; i < n; i++)
            cin >> widths[i];

        vector<int> lis, lds;
        int lisOptimal = 0;
        int ldsOptimal = 0;
        if (n > 0) {
            lis.push_back(widths[0]);
            lds.push_back(widths[0]);
            lisOptimal = lis[0];
            ldsOptimal = lds[0];
        }
        for (int i = 1; i < n; i++) {
            int lisMax = widths[i];
            int ldsMax = lisMax;
            for (int j = 0; j < i; j++) {
                if (heights[j] < heights[i])
                    lisMax = max(lisMax, widths[i] + lis[j]);
                else if (heights[j] > heights[i])
                    ldsMax = max(ldsMax, widths[i] + lds[j]);
            }
            lis.push_back(lisMax);
            lds.push_back(ldsMax);
            lisOptimal = max(lisOptimal, lisMax);
            ldsOptimal = max(ldsOptimal, ldsMax);
        }

        if (lisOptimal < ldsOptimal)
            cout << "Case " << ci << ". Decreasing (" << ldsOptimal << "). Increasing (" << lisOptimal << ").\n";
        else
            cout << "Case " << ci << ". Increasing (" << lisOptimal << "). Decreasing (" << ldsOptimal << ").\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_11790();
    return 0;
}

