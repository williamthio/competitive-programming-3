#include <iostream>
#include <cstring>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

void uva_01103() {
    char hieroglyphs[] = "WAKJSD";
    int h, w;
    int ci = 0;
    while (cin >> h, cin >> w, h && w) {
        int image[200][200];

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                char c;
                cin >> c;
                int bin = c > '9' ? c - 'a' + 10 : c - '0';
                int k = 4;
                while (k--)
                    image[i][j * 4 + 3 - k] = !!(bin & (1 << k));
            }
        }

        function<void(int, int)> ffWhite= [&](int row, int col) {
            if (row < 0 || row >= h || col < 0 || col >= w * 4)
                return;
            if (image[row][col] != 0)
                return;
            image[row][col] = -1;
            ffWhite(row + 1, col);
            ffWhite(row - 1, col);
            ffWhite(row, col + 1);
            ffWhite(row, col - 1);
        };

        for (int i = 0; i < h; i++) {
            ffWhite(i, 0);
            ffWhite(i, w * 4 - 1);
        }

        for (int i = 0; i < w * 4; i++) {
            ffWhite(0, i);
            ffWhite(h - 1, i);
        }

        int count;
        function<void(int, int)> ffBlack= [&](int row, int col) {
            if (row < 0 || row >= h || col < 0 || col >= w * 4)
                return;
            if (image[row][col] == 0) {
                count++;
                ffWhite(row, col);
                return;
            }
            if (image[row][col] != 1)
                return;
            image[row][col] = -1;
            ffBlack(row + 1, col);
            ffBlack(row - 1, col);
            ffBlack(row, col + 1);
            ffBlack(row, col - 1);
        };

        cout << "Case " << ++ci << ": ";
        string output = "";
        for (int row = 0; row < h; row++) {
            for (int col = 0; col < w * 4; col++) {
                if (image[row][col] == 1) {
                    count = 0;
                    ffBlack(row, col);
                    output += hieroglyphs[count];
                }
            }
        }
        sort(output.begin(), output.end());
        cout << output << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_01103();
    return 0;
}

