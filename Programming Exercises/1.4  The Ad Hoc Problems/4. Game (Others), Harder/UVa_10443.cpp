#include <iostream>
#include <functional>

using namespace std;

void uva_10443() {
    // [0] -> Row, [1] -> Col
    const int kDirection[][2] = {
        {-1, 0}, {1, 0},
        {0, -1}, {0, 1}
    };
    const int kDirectionSize = 4;

    int tc;
    bool start = true;
    cin >> tc;
    while (tc--) {
        if (!start)
            cout << "\n";
        start = false;

        int rowSize, colSize, numDays;
        cin >> rowSize;
        cin >> colSize;
        cin >> numDays;

        char grid[100][100];
        for (int row = 0; row < rowSize; row++)
            for (int col = 0; col < colSize; col++)
                cin >> grid[row][col];

        auto getLoser = [&](char winner) -> char {
            if (winner == 'R')
                return 'S';
            else if (winner == 'P')
                return 'R';
            else
                return 'P';
        };

        function<void(bool[][100], int, int, char, bool)> conquer =
            [&](bool visited[][100], int row, int col, char conqueror, bool start) {
            if (!visited[row][col]) {
                if (!start)
                    visited[row][col] = true;
                char conquered = grid[row][col];
                grid[row][col] = conqueror;
                for (int i = 0; i < kDirectionSize; i++) {
                    int drow = row + kDirection[i][0];
                    int dcol = col + kDirection[i][1];
                    if (drow >= 0 && drow < rowSize && dcol >= 0 && dcol < colSize) {
                        if (getLoser(conquered) == grid[drow][dcol])
                            conquer(visited, drow, dcol, conquered, false);
                    }
                }
            }
        };

        while (numDays--) {
            bool visited[100][100] = { false };
            for (int row = 0; row < rowSize; row++) {
                for (int col = 0; col < colSize; col++) {
                    if (!visited[row][col])
                        conquer(visited, row, col, grid[row][col], true);
                }
            }
        }

        for (int row = 0; row < rowSize; row++) {
            for (int col = 0; col < colSize; col++) {
                cout << grid[row][col];
            }
            cout << "\n";
        }
    }
}
