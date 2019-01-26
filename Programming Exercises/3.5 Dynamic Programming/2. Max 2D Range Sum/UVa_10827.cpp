#include <iostream>

using namespace std;

void uva_10827() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        if (n == 1) {
            int value;
            cin >> value;
            cout << value << "\n";
            continue;
        }

        int torus[150][150];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> torus[i][j];
                torus[n + i][j] = torus[i][j];
                torus[i][n + j] = torus[i][j];
                torus[n + i][n + j] = torus[i][j];
            }
        }
 
        for (int i = 0; i < (n << 1) - 2; i++) {
            for (int j = 0; j < (n << 1) - 2; j++) {
                if (i > 0)
                    torus[i][j] += torus[i - 1][j];
                if (j > 0)
                    torus[i][j] += torus[i][j - 1];
                if (i > 0 && j > 0)
                    torus[i][j] -= torus[i - 1][j - 1];
            }
        }

        int optimal = -100 * 75 * 75;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = i; k < (n << 1) - 2 && k - i < n; k++) {
                    for (int l = j; l < (n << 1) - 2 && l - j < n; l++) {
                        int sum = torus[k][l];
                        if (i > 0)
                            sum -= torus[i - 1][l];
                        if (j > 0)
                            sum -= torus[k][j - 1];
                        if (i > 0 && j > 0)
                            sum += torus[i - 1][j - 1];
                        if (optimal < sum)
                            optimal = sum;
                    }
                }
            }
        }

        cout << optimal << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_10827();
    return 0;
}

