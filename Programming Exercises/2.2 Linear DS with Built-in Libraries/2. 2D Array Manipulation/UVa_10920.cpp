#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

void uva_10920() {
    const pair<int, int> kDirections[] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
    int sz;
    while (cin >> sz, sz) {
        long long p;
        cin >> p;
        long long row = (sz + 1) / 2;
        long long col = row;
        int multiplier = 1;
        int turn = 0;
        while (p > 1) {
            pair<int, int> direction = kDirections[turn % 4];
            int rowMovement = direction.first * multiplier;
            int colMovement = direction.second * multiplier;
            row += rowMovement;
            col += colMovement;
            p -= abs(rowMovement + colMovement);
            if (++turn % 2 == 0)
                multiplier++;
        }
        if (p <= 0) {
            long long multiplier = 1 - p;
            pair<int, int> direction = kDirections[(turn - 1) % 4];
            row -= direction.first * multiplier;
            col -= direction.second * multiplier;
        }
        cout << "Line = " << row << ", column = " << col << ".\n";
    }
}
