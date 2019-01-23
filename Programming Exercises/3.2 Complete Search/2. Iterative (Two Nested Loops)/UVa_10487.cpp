#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void uva_10487() {
    int n, ci = 0;
    while (cin >> n, n) {
        cout << "Case " << ++ci << ":\n";

        int arr[1000];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);

        int m;
        cin >> m;

        while (m--) {
            int q;
            cin >> q;

            int i = 0, j = n - 1, closest = -1;
            while (i < j) {
                int left = arr[i];
                int right = arr[j];
                if (closest == -1 || abs(closest - q) > abs(left + right - q))
                    closest = left + right;
                if (left + right < q)
                    i++;
                else if (left + right > q)
                    j--;
                else
                    break;
            }

            cout << "Closest sum to " << q << " is " << closest << ".\n";
        }
    }
}
