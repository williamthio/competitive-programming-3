#include <iostream>
#include <vector>
#include <functional>

using namespace std;

void uva_10855() {
    int bn, sn;
    while (cin >> bn, bn) {
        cin >> sn;
        vector<vector<char>> big, small;
        big.resize(bn);
        small.resize(sn);
        for (int i = 0; i < bn; i++) {
            big[i].resize(bn);
            for (int j = 0; j < bn; j++)
                cin >> big[i][j];
        }
        for (int i = 0; i < sn; i++) {
            small[i].resize(sn);
            for (int j = 0; j < sn; j++)
                cin >> small[i][j];
        }

        auto isSame = [&](int row, int col) -> bool {
            for (int i = 0; i < sn; i++) {
                for (int j = 0; j < sn; j++) {
                    if (big[row + i][col + j] != small[i][j]) {
                        return false;
                    }
                }
            }
            return true;
        };

        auto rotate = [&]() {
            vector<vector<char>> rotated = small;
            for (int i = 0; i < sn; i++) {
                for (int j = 0; j < sn; j++) {
                    rotated[i][j] = small[sn - 1 - j][i];
                }
            }
            small = rotated;
        };

        for (int rotation = 0; rotation < 4; rotation++) {
            if (rotation > 0) {
                cout << " ";
                rotate();
            }
            int count = 0;
            for (int row = 0; row <= bn - sn; row++) {
                for (int col = 0; col <= bn - sn; col++) {
                    if (isSame(row, col)) {
                        count++;
                    }
                }
            }
            cout << count;
        }
        cout << "\n";
    }
}
