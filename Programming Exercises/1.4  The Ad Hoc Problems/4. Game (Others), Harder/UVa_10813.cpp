#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

void uva_10813() {
    int n;
    cin >> n;
    while (n--) {
        int card[5][5];
        unordered_map<int, pair<int, int>> numPositions;
        bool checked[5][5] = { false };
        checked[2][2] = true;

        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                if (row == 2 && col == 2)
                    continue;
                cin >> card[row][col];
                numPositions[card[row][col]] = make_pair(row, col);
            }
        }

        bool gameOver = false;
        int checkedCount = 0;
        for (int i = 0; i < 75; i++) {
            int num;
            cin >> num;

            if (gameOver)
                continue;

            if (numPositions.find(num) == numPositions.end())
                continue;

            pair<int, int> pos = numPositions[num];
            checked[pos.first][pos.second] = true;
            checkedCount++;

            if (checkedCount >= 4) {
                bool win = true;

                // Vertical
                for (int row = 0; row < 5; row++) {
                    win = win && checked[row][pos.second];
                    if (!win)
                        break;
                }
                if (win) {
                    cout << "BINGO after " << i + 1 << " numbers announced\n";
                    gameOver = true;
                    continue;
                }

                win = true;
                // Horizontal
                for (int col = 0; col < 5; col++) {
                    win = win && checked[pos.first][col];
                    if (!win)
                        break;
                }
                if (win) {
                    cout << "BINGO after " << i + 1 << " numbers announced\n";
                    gameOver = true;
                    continue;
                }

                // Diagonal
                win = true;
                int row = 0, col = 0;
                if (pos.first == pos.second) {
                    while (row < 5) {
                        win = win && checked[row++][col++];
                        if (!win)
                            break;
                    }
                }
                else if (pos.first + pos.second == 4) {
                    row = 0;
                    col = 4;
                    while (row < 5) {
                        win = win && checked[row++][col--];
                        if (!win)
                            break;
                    }
                }
                if (win && (pos.first == pos.second || pos.first + pos.second == 4)) {
                    cout << "BINGO after " << i + 1 << " numbers announced\n";
                    gameOver = true;
                    continue;
                }
            }
        }
    }
}
