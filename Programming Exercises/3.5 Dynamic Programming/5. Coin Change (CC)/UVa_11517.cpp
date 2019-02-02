#include <iostream>
#include <functional>
#include <cstring>

using namespace std;

void uva_11517() {
    int tc;
    cin >> tc;
    while (tc--) {
        int price, n;
        cin >> price;
        cin >> n;

        int bills[100];
        for (int i = 0; i < n; i++)
            cin >> bills[i];

        int memo[100][10001][2];
        memset(memo, -1, sizeof memo);

        function<int *(int, int)> pay = [&](int idx, int value) -> int * {
            if (value <= 0) {
                int *amount = new int[2];
                amount[0] = value;
                amount[1] = 0;
                return amount;
            }
            if (idx == n) {
                int *amount = new int[2];
                amount[0] = 1 << 31;
                amount[1] = 1 << 30;
                return amount;
            }

            if (memo[idx][value][1] != -1)
                return memo[idx][value];

            int *without = pay(idx + 1, value); 
            int *with = pay(idx + 1, value - bills[idx]);

            if (with[0] > without[0]) {
                memo[idx][value][0] = with[0];
                memo[idx][value][1] = with[1] + 1;
            }
            else if (with[0] < without[0]) {
                memo[idx][value][0] = without[0];
                memo[idx][value][1] = without[1];
            }
            else if (with[1] + 1 < without[1]) {
                memo[idx][value][0] = with[0];
                memo[idx][value][1] = with[1] + 1;
            }
            else {
                memo[idx][value][0] = without[0];
                memo[idx][value][1] = without[1];
            }

            return memo[idx][value];
        };

        int *amount = pay(0, price);
        cout << price - amount[0] << " " << amount[1] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_11517();
    return 0;
}

