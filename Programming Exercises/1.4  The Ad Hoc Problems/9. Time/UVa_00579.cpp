#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>

using namespace std;

void uva_00579() {
    int h = 0, m = 0, ir;
    while (ir = scanf("%d:%d", &h, &m), ir == 2 && (h || m)) {
        int md = m * 6;
        double hd = h * 30 + 30 * m / 60.0;
        double large = md > hd ? md : hd;
        double small = hd < md ? hd : md;
        if (large - small <= 180) {
            printf("%.3f\n", large - small);
        }
        else {
            printf("%.3f\n", 360 - large + small);
        }
    }
}
