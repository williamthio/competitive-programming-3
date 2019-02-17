#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

void e_3_5_3_1_lis() {
    int arr[] = { -7, 10, 9, 2, 3, 8, 8 };
    int n = sizeof arr / sizeof *arr;

    int lis[100];
    lis[0] = 1;

    for (int i = 1; i < n; i++) {
        int maxLis = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i])
                maxLis = max(maxLis, lis[j]);
        }
        lis[i] = maxLis + 1;
    }

    cout << *max_element(lis, lis + n) << "\n";
}

void e_3_5_3_1_knapsack_uva_10130() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        int prices[1000];
        int weights[1000];
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
            cin >> weights[i];
        }

        int ans = 0;
        int g;
        cin >> g;
        while (g--) {
            int mw;
            cin >> mw;

            int states[2][31] = { 0 };

            //for (int i = 0; i <= mw; i++) {
            //    if (i < weights[0])
            //        cout << "   0";
            //   else
            //        cout << setw(4) << prices[0];
            //}
            //cout << "\n";

            for (int i = weights[0]; i <= mw; i++)
                states[0][i] = prices[0];

            for (int i = 1; i < n; i++) {
                for (int j = 0; j <= mw; j++) {
                    if (j < weights[i])
                        states[i % 2][j] = states[(i + 1) % 2][j];
                    else
                        states[i % 2][j] = max(states[(i + 1) % 2][j], states[(i + 1) % 2][j - weights[i]] + prices[i]);
                    //cout << setw(4) << states[i % 2][j];
                }
                //cout << "\n";
            }
            //cout << "\n";

            ans += states[(n + 1) % 2][mw];
        }

        cout << ans << "\n";
    }
}

void e_3_5_3_1_cc_uva_00674() {
    int types[] = { 1, 5, 10, 25, 50 };
    int states[5][7490];
    for (int i = 0; i < 7590; i++)
        states[0][i] = 1;
    for (int i = 1; i < 5; i++)
        states[i][0] = 1;
    int money;
    while (cin >> money, !cin.fail()) {
        int i;
        for (i = 1; i < 5 && types[i] <= money; i++) {
            for (int m = 1; m <= money; m++) {
                if (m < types[i])
                    states[i][m] = states[i - 1][m];
                else
                    states[i][m] = states[i][m - types[i]] + states[i - 1][m];
                //cout << setw(4) << states[i][m];
            }
            //cout << "\n";
        }
        cout << states[i - 1][money] << "\n";
    }
}

void e_3_5_3_1_tsp_uva_10496() {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    e_3_5_3_1_cc_uva_00674();
    return 0;
}

