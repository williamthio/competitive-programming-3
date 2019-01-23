#include <iostream>

using namespace std;

void uva_12032() {
    int tc;
    cin >> tc;
    for (int ci = 1; ci <= tc; ci++) {
        int n;
        cin >> n;
        
        int rungs[100000];
        for (int i = 0; i < n; i++)
            cin >> rungs[i];

        int low = 1;
        int high = 10000000;
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;

            bool valid = true;
            int curr = 0;
            int k = mid;
            for (int i = 0; i < n; i++) {
                int h = rungs[i] - curr;
                if (h > k) {
                    valid = false;
                    break;
                }
                else if (h == k) {
                    k--;
                }
                curr += h;
            }

            if (valid) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        cout << "Case " << ci << ": " << ans << "\n";
    }
}
