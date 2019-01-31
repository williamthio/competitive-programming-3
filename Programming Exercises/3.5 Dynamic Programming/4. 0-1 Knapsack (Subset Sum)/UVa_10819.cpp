#include <iostream>
#include <functional>
#include <cstring>
#include <algorithm>

using namespace std;

void uva_10819() {
    int m;
    while (cin >> m, !cin.fail()) {
        int n;
        cin >> n;

        int prices[100], favours[100];
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
            cin >> favours[i];
        }

        int memo[100][10201];
        memset(memo, -1, sizeof memo);

        function<int(int, int)> shop = [&](int idx, int money) -> int {
            if (money > m + 200)
                return -99999999;
            if (idx == n) {
                if (money <= m || money > 2000 && money <= m + 200)
                    return 0;
                return -99999999;
            }
            if (memo[idx][money] != -1)
                return memo[idx][money];
            return memo[idx][money] = max(shop(idx + 1, money), favours[idx] + shop(idx + 1, money + prices[idx]));
        };

        cout << shop(0, 0) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_10819();
    return 0;
}

