#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

void uva_11553() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int grid[8][8];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];

        int rows[8];
        for (int i = 0; i < n; i++)
            rows[i] = i;

        int min = 8000;
        do {
            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += grid[rows[i]][i];
            if (min > sum)
                min = sum;
        } while (next_permutation(rows, rows + n));

        cout << min << "\n";
    }
}
