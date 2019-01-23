#include <iostream>
#include <iomanip>
#include <functional>
#include <string>

using namespace std;

void uva_00183() {
    char format;
    while (cin >> format, format != '#') {
        int rows, cols;
        cin >> rows;
        cin >> cols;

        cout << (format == 'B' ? 'D' : 'B')
            << right
            << setw(4) << rows
            << setw(4) << cols
            << left << "\n";
        string output = "";
        int enterCount = 0;

        if (format == 'B') {
            char bm[200][200];
            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++)
                    cin >> bm[row][col];
            }
            function<void(int, int, int, int)> process = [&](int sr, int er, int sc, int ec) {
                char out = '-';
                for (int row = sr; row <= er && out != 'D'; row++) {
                    for (int col = sc; col <= ec && out != 'D'; col++) {
                        if (out == '-')
                            out = bm[row][col];
                        else if (out != bm[row][col])
                            out = 'D';
                    }
                }

                output += out;
                if ((output.size() - enterCount) % 50 == 0) {
                    output += '\n';
                    enterCount++;
                }

                if (out == 'D') {
                    int rowMid = (sr + er) / 2;
                    int colMid = (sc + ec) / 2;
                    process(sr, rowMid, sc, colMid);
                    if (sc < ec)
                        process(sr, rowMid, colMid + 1, ec);
                    if (sr < er)
                        process(rowMid + 1, er, sc, colMid);
                    if (sc < ec && sr < er)
                        process(rowMid + 1, er, colMid + 1, ec);
                }
            };

            process(0, rows - 1, 0, cols - 1);
        }
        else {
            int idx = 0;
            char bit;
            char bm[200][200];
            function<void(int, int, int, int)> process = [&](int sr, int er, int sc, int ec) {
                cin >> bit;
                if (bit == 'D') {
                    int rowMid = (sr + er) / 2;
                    int colMid = (sc + ec) / 2;
                    process(sr, rowMid, sc, colMid);
                    if (sc < ec)
                        process(sr, rowMid, colMid + 1, ec);
                    if (sr < er)
                        process(rowMid + 1, er, sc, colMid);
                    if (sc < ec && sr < er)
                        process(rowMid + 1, er, colMid + 1, ec);
                }
                else {
                    for (int row = sr; row <= er; row++) {
                        for (int col = sc; col <= ec; col++)
                            bm[row][col] = bit;
                    }
                }
            };

            process(0, rows - 1, 0, cols - 1);

            for (int row = 0; row < rows; row++) {
                for (int col = 0; col < cols; col++) {
                    output += bm[row][col];
                    if ((output.size() - enterCount) % 50 == 0) {
                        output += '\n';
                        enterCount++;
                    }
                }
            }
        }

        if (output[output.size() - 1] != '\n')
            output += '\n';

        cout << output;
    }
}
