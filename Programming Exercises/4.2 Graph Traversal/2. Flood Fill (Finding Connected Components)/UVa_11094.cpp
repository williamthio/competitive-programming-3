#include <iostream>
#include <functional>

using namespace std;

void uva_11094() {
    int m, n;
    while (cin >> m, !cin.fail()) {
        cin >> n;

        char grid[20][20];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];

        int x, y;
        cin >> x;
        cin >> y;

        char land = grid[x][y];
        int area;
        function<void(int, int)> ff = [&](int row, int col) {
            if (row < 0 || row >= m)
                return;
            if (col == -1)
                col = n - 1;
            else if (col == n)
                col = 0;
            if (grid[row][col] != land)
                return;
            area++;
            grid[row][col] = land + 1;
            ff(row + 1, col);
            ff(row - 1, col);
            ff(row, col + 1);
            ff(row, col - 1);
        };

        area = 0;
        ff(x, y);

        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                area = 0;
                ff(i, j);
                maxArea = max(maxArea, area);
            }
        }

        cout << maxArea << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_11094();
    return 0;
}

