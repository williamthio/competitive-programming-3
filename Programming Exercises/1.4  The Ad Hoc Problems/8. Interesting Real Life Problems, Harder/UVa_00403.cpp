#include <iostream>
#include <string>
#include <functional>
#include <cctype>
#include <limits>
#include <cmath>

using namespace std;

void uva_00403() {
    const string kC5Letters[][5] = {
        { ".***..", "*...*.", "*****.", "*...*.", "*...*." },
        { "****..", "*...*.", "****..", "*...*.", "****.." },
        { ".****.", "*...*.", "*.....", "*.....", ".****." },
        { "****..", "*...*.", "*...*.", "*...*.", "****.." },
        { "*****.", "*.....", "***...", "*.....", "*****." },
        { "*****.", "*.....", "***...", "*.....", "*....." },
        { ".****.", "*.....", "*..**.", "*...*.", ".***.." },
        { "*...*.", "*...*.", "*****.", "*...*.", "*...*." },
        { "*****.", "..*...", "..*...", "..*...", "*****." },
        { "..***.", "...*..", "...*..", "*..*..", ".**..." },
        { "*...*.", "*..*..", "***...", "*..*..", "*...*." },
        { "*.....", "*.....", "*.....", "*.....", "*****." },
        { "*...*.", "**.**.", "*.*.*.", "*...*.", "*...*." },
        { "*...*.", "**..*.", "*.*.*.", "*..**.", "*...*." },
        { ".***..", "*...*.", "*...*.", "*...*.", ".***.." },
        { "****..", "*...*.", "****..", "*.....", "*....." },
        { ".***..", "*...*.", "*...*.", "*..**.", ".****." },
        { "****..", "*...*.", "****..", "*..*..", "*...*." },
        { ".****.", "*.....", ".***..", "....*.", "****.." },
        { "*****.", "*.*.*.", "..*...", "..*...", ".***.." },
        { "*...*.", "*...*.", "*...*.", "*...*.", ".***.." },
        { "*...*.", "*...*.", ".*.*..", ".*.*..", "..*..." },
        { "*...*.", "*...*.", "*.*.*.", "**.**.", "*...*." },
        { "*...*.", ".*.*..", "..*...", ".*.*..", "*...*." },
        { "*...*.", ".*.*..", "..*...", "..*...", "..*..." },
        { "*****.", "...*..", "..*...", ".*....", "*****." },
        { "......", "......", "......", "......", "......" }
    };

    char grid[60][61];

    auto cleanGrid = [&]() {
        for (int i = 0; i < 60; i++) {
            for (int j = 0; j < 61; j++) {
                if (j == 60) {
                    grid[i][j] = '\0';
                    continue;
                }
                grid[i][j] = '.';
            }
        }
    };

    auto placeC1 = [&](string s, int row, int col) {
        if (row < 0 || row >= 60 || col < 0 || col >= 60)
            return;
        for (int i = 0, n = s.size(); i < n; i++) {
            if (col + i >= 60)
                break;
            if (isspace(s[i]))
                continue;
            grid[row][col + i] = s[i];
        }
    };

    auto placeC5 = [&](char c, int row, int col) -> bool {
        if (isspace(c) || col < -5)
            return true;
        if (row < 0 || row >= 60 || col >= 60 || !isupper(c))
            return false;
        auto letter = kC5Letters[c - 'A'];
        for (int i = 0; i < 5; i++) {
            if (row + i >= 60)
                break;
            for (int j = (col < 0 ? abs(col) : 0); j < 6; j++) {
                if (col + j >= 60)
                    break;
                if (letter[i][j] == '.')
                    continue;
                grid[row + i][col + j] = letter[i][j];
            }
        }
        return true;
    };

    auto place = [&](string s, string type, int row, int col) {
        if (type[1] == '1') {
            placeC1(s, row - 1, col - 1);
        }
        else {
            for (int i = 0, n = s.size(); i < n; i++) {
                if (!placeC5(s[i], row - 1, col - 1 + 6 * i))
                    break;
            }
        }
    };

    cleanGrid();

    string cmd, type, line;
    int row, col;
    while (cin >> cmd, !cin.fail()) {
        if (cmd.compare(".EOP") == 0) {
            for (int i = 0; i < 60; i++)
                cout << grid[i] << "\n";
            cout << "\n------------------------------------------------------------\n\n";
            cleanGrid();
            continue;
        }

        cin >> type;
        cin >> row;
        if (cmd[1] == 'P')
            cin >> col;

        cin.ignore(numeric_limits<streamsize>::max(), '|');
        getline(cin, line);
        line.pop_back();

        switch (cmd[1]) {
        case 'P':
            place(line, type, row, col);
            break;
        case 'L':
            place(line, type, row, 1);
            break;
        case 'R':
            if (type[1] == '1')
                place(line, type, row, 61 - line.size());
            else
                place(line, type, row, 61 - line.size() * 6);
            break;
        case 'C':
            if (type[1] == '1')
                place(line, type, row, 31 - line.size() / 2);
            else
                place(line, type, row, 31 - line.size() * 3);
            break;
        }
    }
}
