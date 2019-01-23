#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

void uva_10189() {
    // [0] -> Column, [1] -> Row
    const vector<vector<int>> surrounding = {
        {-1, -1}, {0, -1}, {1, -1},
        {-1,  0},          {1,  0},
        {-1,  1}, {0,  1}, {1,  1}
    };
    const int surroundingSize = surrounding.size();
    const int kMine = -1;

    int rowSize, colSize, fc = 0;
    while (cin >> rowSize, cin >> colSize, rowSize && colSize) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (fc > 0)
            cout << "\n";

        int field[100][100] = { 0 };

        // Field scan
        char c;
        int row, col;
        for (row = 0; row < rowSize; row++) {
            for (col = 0; col < colSize; col++) {
                cin >> c;
                if (c == '*') {
                    field[row][col] = kMine;

                    // Add surrounding values
                    for (int i = 0; i < surroundingSize; i++) {
                        vector<int> dir = surrounding[i];
                        int drow = row + dir[1];
                        int dcol = col + dir[0];
                        if (drow >= 0 && drow < rowSize
                            && dcol >= 0 && dcol < colSize
                            && field[drow][dcol] != kMine) {
                            field[drow][dcol] += 1;
                        }
                    }
                }
            }
        }

        cout << "Field #" << ++fc << ":\n";
        for (row = 0; row < rowSize; row++) {
            for (col = 0; col < colSize; col++) {
                if (field[row][col] == -1)
                    cout << "*";
                else
                    cout << field[row][col];
            }
            cout << "\n";
        }
    }
}
