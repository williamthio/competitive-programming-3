#include <iostream>

using namespace std;

void uva_11951() {
    int tc;
    cin >> tc;
    for (int ci = 1; ci <= tc; ci++) {
        int n, m, budget;
        cin >> n;
        cin >> m;
        cin >> budget;

        int prices[100][100];
        int area[100][100];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> prices[i][j];
                area[i][j] = prices[i][j];
                if (i > 0)
                    area[i][j] += area[i - 1][j];
                if (j > 0)
                    area[i][j] += area[i][j - 1];
                if (i > 0 && j > 0)
                    area[i][j] -= area[i - 1][j - 1];
            }
        }

        int s = 0;
        int p = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (prices[i][j] > budget)
                    continue;
                for (int k = i; k < n; k++) {
                    for (int l = j; l < m; l++) {
                        long long sum = area[k][l];
                        if (i > 0)
                            sum -= area[i - 1][l];
                        if (j > 0)
                            sum -= area[k][j - 1];
                        if (i > 0 && j > 0)
                            sum += area[i - 1][j - 1];
                        if (sum <= budget) {
                            int areaSize = (k - i + 1) * (l - j + 1);
                            if (s < areaSize) {
                                s = areaSize;
                                p = sum;
                            }
                            else if (s == areaSize && p > sum) {
                                p = sum;
                            }
                        }
                    }
                }
            }
        }

        cout << "Case #" << ci << ": " << s << " " << p << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_11951();
    return 0;
}

