#include <iostream>
#include <functional>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

void uva_11566() {
    int n, x, t, k;
    while (cin >> n, cin >> x, cin >> t, cin >> k, n || x || t || k) {
        int prices[100];
        int favours[100][11];
        for (int i = 0; i < k; i++) {
            cin >> prices[i];
            for (int j = 0; j < n + 1; j++)
                cin >> favours[i][j];
        }

        function<int(int)> bill = [&](int total) -> int {
            return ceil((total + t * (n + 1)) * 1.1 - 1e-6);
        }; 

        function<int(int)> favourSum = [&](int dish) -> int {
            int sum = 0;
            for (int i = 0; i < n + 1; i++)
                sum += favours[dish][i];
            return sum;
        };

        int memo[100][22][2200];
        memset(memo, -1, sizeof memo);

        function<int(int, int, int)> order = [&](int idx, int dishes, int total) -> int {
            if (idx == k || dishes == 2 * (n + 1) || bill(total) == x * (n + 1))
                return 0;

            if (memo[idx][dishes][total] != -1)
                return memo[idx][dishes][total];

            int favour = order(idx + 1, dishes, total);

            if (bill(total + prices[idx]) <= x * (n + 1))
                favour = max(favour, favourSum(idx) + order(idx + 1, dishes + 1, total + prices[idx]));

            if (dishes + 2 <= 2 * (n + 1) && bill(total + prices[idx] * 2) <= x * (n + 1))
                favour = max(favour, favourSum(idx) * 2 + order(idx + 1, dishes + 2, total + prices[idx] * 2));

            return memo[idx][dishes][total] = favour;
        };

        cout << fixed << setprecision(2) << (order(0, 0, 0) / (n + 1.0)) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_11566();
    return 0;
}

