#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <queue>
#include <cmath>
#include <functional>
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
    int tc;
    cin >> tc;
    while (tc--) {
        int size;
        cin >> size;
        cin >> size;

        int bs[11][2];
        cin >> bs[0][0];
        cin >> bs[0][1];

        function<int(int, int)> dist = [&](int idx1, int idx2) -> int {
            return abs(bs[idx1][0] - bs[idx2][0]) + abs(bs[idx1][1] - bs[idx2][1]);
        };

        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> bs[i][0];
            cin >> bs[i][1];
        }

        int states[1 << 10][10];

        for (int i = 0; i < n; i++)
            states[1 << i][i] = dist(0, i + 1);

        for (int visited = 2; visited < (1 << n); visited++) {
            if (!(visited & (visited - 1)))
                continue;
            for (int i = 0; i < n; i++) {
                if (!(visited & (1 << i)))
                    continue;
                int prev = visited & (~(1 << i));
                int minDist = 1 << 30;
                for (int j = 0; j < n; j++) {
                    if (!(prev & (1 << j)))
                        continue;
                    if (minDist > states[prev][j] + dist(j + 1, i + 1))
                        minDist = states[prev][j] + dist(j + 1, i + 1);
                }
                states[visited][i] = minDist;
            }
        }

        int optimal = 1 << 30;
        for (int i = 0; i < n; i++) {
            if (optimal > states[(1 << n) - 1][i] + dist(i + 1, 0))
                optimal = states[(1 << n) - 1][i] + dist(i + 1, 0);
        }

        cout << "The shortest path has length " << optimal << "\n";
    }
}

void e_3_5_3_1_uva_10003() {
    int len;
    while (cin >> len, len) {
        int n;
        cin >> n;

        int cuts[51];
        cuts[0] = 0;
        cuts[n + 1] = len;

        for (int i = 1; i <= n; i++)
            cin >> cuts[i];

        n += 2;

        int states[51][51];
        
        for (int i = 0; i + 1 < n; i++)
            states[i][i + 1] = 0;

        for (int len = 2; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                int minPrice = 1 << 30;
                for (int j = i + 1; j < i + len; j++)
                    minPrice = min(minPrice, states[i][j] + states[j][i + len] + cuts[i + len] - cuts[i]);
                states[i][i + len] = minPrice;
            }
        }

        cout << "The minimum cutting is " << states[0][n - 1] << ".\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    e_3_5_3_1_uva_10003();
    return 0;
}

