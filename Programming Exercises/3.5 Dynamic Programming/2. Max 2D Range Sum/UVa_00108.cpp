#include <iostream>

using namespace std;

void uva_00108() {
    int n;
    while (cin >> n, !cin.fail()) {
        int rect[100][100];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> rect[i][j];
                if (i > 0)
                    rect[i][j] += rect[i - 1][j];
                if (j > 0)
                    rect[i][j] += rect[i][j - 1];
                if (i > 0 && j > 0)
                    rect[i][j] -= rect[i - 1][j - 1];
            }
        }

        int optimal = -127 * 100 * 100;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = i; k < n; k++) {
                    for (int l = j; l < n; l++) {
                        int sum = rect[k][l];
                        if (i > 0)
                            sum -= rect[i - 1][l];
                        if (j > 0)
                            sum -= rect[k][j - 1];
                        if (i > 0 && j > 0)
                            sum += rect[i - 1][j - 1];
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
    uva_00108();
    return 0;
}

