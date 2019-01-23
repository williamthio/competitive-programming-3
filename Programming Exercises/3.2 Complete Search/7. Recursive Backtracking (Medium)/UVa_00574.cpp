#include <iostream>
#include <functional>
#include <string>
#include <unordered_map>

using namespace std;

void uva_00574() {
    int t, n;
    while (cin >> t, cin >> n, n) {
        cout << "Sums of " << t << ":\n";

        int arr[12];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int nums[12];
        unordered_map<string, bool> exist;
        function<void(int, int, int)> search = [&](int prev, int idx, int sum) {
            if (sum > t)
                return;
            if (sum == t) {
                string s = "";
                for (int i = 0; i < idx; i++) {
                    if (i > 0)
                        s += '+';
                    s += to_string(nums[i]);
                }
                if (!exist[s]) {
                    exist[s] = true;
                    cout << s << "\n";
                }
            }
            for (int i = prev + 1; i < n; i++) {
                nums[idx] = arr[i];
                search(i, idx + 1, sum + arr[i]);
            }
        };

        search(-1, 0, 0);

        if (exist.empty())
            cout << "NONE\n";
    }
}
