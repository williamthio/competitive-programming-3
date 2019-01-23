#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

void uva_11085() {
    int validBoards[92][8];
    int vbn = 0;

    int row[8];
    auto check = [&](int r, int c) -> bool {
        for (int i = 0; i < c; i++) {
            if (row[i] == r || abs(row[i] - r) == abs(i - c))
                return false;
        }
        return true;
    };

    function<void(int)> generate = [&](int c) {
        if (c == 8) {
            for (int i = 0; i < 8; i++)
                validBoards[vbn][i] = row[i] + 1;
            vbn++;
        }
        else {
            for (int r = 0; r < 8; r++) {
                if (check(r, c)) {
                    row[c] = r;
                    generate(c + 1);
                }
            }
        }
    };

    generate(0);

    int tc = 0;
    while (cin >> row[0], !cin.fail()) {
        for (int i = 1; i < 8; i++)
            cin >> row[i];
        int min = 888;
        for (int b = 0; b < vbn; b++) {
            int moves = 0;
            for (int c = 0; c < 8; c++) {
                if (row[c] != validBoards[b][c])
                    moves++;
            }
            if (min > moves) {
                min = moves;
                if (min == 0)
                    break;
            }
        }
        cout << "Case " << ++tc << ": " << min << "\n";
    }
}
