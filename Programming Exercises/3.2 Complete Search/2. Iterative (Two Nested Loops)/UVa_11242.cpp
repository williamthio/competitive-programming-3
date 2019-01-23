#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

void uva_11242() {
    int f;
    while (cin >> f, f) {
        int r;
        cin >> r;
        
        int fs[10], rs[10];
        for (int i = 0; i < f; i++)
            cin >> fs[i];
        for (int i = 0; i < r; i++)
            cin >> rs[i];

        double ratios[100];
        int rti = 0;
        for (int fi = 0; fi < f; fi++) {
            for (int ri = 0; ri < r; ri++)
                ratios[rti++] = (double)rs[ri] / fs[fi];
        }
        sort(ratios, ratios + rti);

        double max = -1;
        for (int i = 1; i < rti; i++) {
            if (max < ratios[i] / ratios[i - 1])
                max = ratios[i] / ratios[i - 1];
        }

        cout << fixed << setprecision(2) << max << "\n";
    }
}
