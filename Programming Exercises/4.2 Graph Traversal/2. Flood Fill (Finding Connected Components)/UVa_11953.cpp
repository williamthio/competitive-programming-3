#include <iostream>
#include <functional>

using namespace std;

void uva_11953() {
    int tc;
    cin >> tc;
    for (int ci = 1; ci <= tc; ci++) {
        int n;
        cin >> n;

        char grid[100][100];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];

        function<void(int, int)> ff = [&](int row, int col) {
            if (row < 0 || row >= n || col < 0 || col >= n)
                return;
            if (grid[row][col] == '.')
                return;
            grid[row][col] = '.';
            ff(row + 1, col);
            ff(row - 1, col);
            ff(row, col + 1);
            ff(row, col - 1);
        };

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'x') {
                    count++;
                    ff(i, j);
                }
            }
        }

        cout << "Case " << ci << ": " << count << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_11953();
    return 0;
}

