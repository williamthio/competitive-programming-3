#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

void uva_10660() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        int areas[25] = { 0 };
        while (n--) {
            int row;
            int col;
            cin >> row;
            cin >> col;
            cin >> areas[row * 5 + col];
        }

        int minArr[5];
        int min = -1;
        auto check = [&](int *arr, int occupied) {
            int covered = 0;
            int coveredAreas[25] = { 0 };
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 25; j++) {
                    if (!areas[j] || (occupied & (1 << j)) != 0)
                        continue;
                    int distance = (abs(arr[i] / 5 - j / 5) + abs(arr[i] % 5 - j % 5)) * areas[j];
                    if ((covered & (1 << j)) == 0 || coveredAreas[j] > distance) {
                        coveredAreas[j] = distance;
                        covered |= 1 << j;
                    }
                }
            }
            int sum = 0;
            for (int i = 0; i < 25; i++)
                sum += coveredAreas[i];
            if (min == -1 || min > sum) {
                min = sum;
                for (int i = 0; i < 5; i++)
                    minArr[i] = arr[i];
            }
        };

        for (int a = 0; a < 21; a++) {
            for (int b = a + 1; b < 22; b++) {
                for (int c = b + 1; c < 23; c++) {
                    for (int d = c + 1; d < 24; d++) {
                        for (int e = d + 1; e < 25; e++) {
                            int arr[] = { a, b, c, d, e };
                            int occupied = 0;
                            occupied |= 1 << a;
                            occupied |= 1 << b;
                            occupied |= 1 << c;
                            occupied |= 1 << d;
                            occupied |= 1 << e;
                            check(arr, occupied);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < 5; i++) {
            if (i > 0)
                cout << " ";
            cout << minArr[i];
        }
        cout << "\n";
    }
}
