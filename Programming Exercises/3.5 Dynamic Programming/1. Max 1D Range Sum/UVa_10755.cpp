#include <iostream>
#include <algorithm>

using namespace std;

void uva_10755() {
    int tc;
    cin >> tc;
    bool start = true;
    while (tc--) {
        int an, bn, cn;
        cin >> an;
        cin >> bn;
        cin >> cn;

        long long heap[20][20][20];
        for (int a = 0; a < an; a++) {
            for (int b = 0; b < bn; b++) {
                for (int c = 0; c < cn; c++) {
                    cin >> heap[a][b][c];
                    if (b > 0)
                        heap[a][b][c] += heap[a][b - 1][c];
                    if (c > 0)
                        heap[a][b][c] += heap[a][b][c - 1];
                    if (b > 0 && c > 0)
                        heap[a][b][c] -= heap[a][b - 1][c - 1];
                }
            }
        }

        long long optimal = heap[an - 1][bn - 1][cn - 1];
        for (int i = 0; i < bn; i++) {
            for (int j = 0; j < cn; j++) {
                for (int k = i; k < bn; k++) {
                    for (int l = j; l < cn; l++) {
                        long long maxSubHeap = (long long)(1 << 31) * 20 * 20 * 20;
                        long long sum = 0;
                        for (int a = 0; a < an; a++) {
                            long long value = heap[a][k][l];
                            if (i > 0)
                                value -= heap[a][i - 1][l];
                            if (j > 0)
                                value -= heap[a][k][j - 1];
                            if (i > 0 && j > 0)
                                value += heap[a][i - 1][j - 1];
                            sum += value;
                            maxSubHeap = max(maxSubHeap, sum);
                            if (sum < 0)
                                sum = 0;
                        }
                        optimal = max(optimal, maxSubHeap);
                    }
                }
            }
        }

        if (!start)
            cout << "\n";
        start = false;
        cout << optimal << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_10755();
    return 0;
}

