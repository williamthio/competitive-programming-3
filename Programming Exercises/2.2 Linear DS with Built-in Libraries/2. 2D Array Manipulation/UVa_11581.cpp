#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void uva_11581() {
    const int kDirections[][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    int tc;
    cin >> tc;
    while (tc--) {
        vector<vector<int>> grid;
        grid.resize(3);
        char c;
        for (int i = 0; i < 3; i++) {
            grid[i].resize(3);
            for (int j = 0; j < 3; j++) {
                cin >> c;
                grid[i][j] = c - '0';
            }
        }

        auto transform = [&]() -> int {
            vector<vector<int>> newGrid = grid;
            int total = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int sum = 0;
                    for (int k = 0; k < 4; k++) {
                        const int *dir = kDirections[k];
                        int row = i + dir[0];
                        int col = j + dir[1];
                        if (row < 0 || row > 2 || col < 0 || col > 2)
                            continue;
                        sum += grid[row][col];
                    }
                    total += sum;
                    newGrid[i][j] = sum % 2;
                }
            }
            grid = newGrid;
            return total;
        };
        
        int i = 0;
        while (transform())
            i++;
        cout << (i - 1) << "\n";
    }
}
