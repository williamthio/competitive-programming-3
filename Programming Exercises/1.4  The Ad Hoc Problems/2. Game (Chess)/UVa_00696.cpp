#include <iostream>
#include <cmath>

using namespace std;

void uva_00696() {
    int m, n;
    while (cin >> m, cin >> n, m || n) {
        int k = 0;

        if ((m == 1 || n == 1) && m > 0 && n > 0)
            k = m < n ? n : m;
        else if ((m == 2 || n == 2) && m > 0 && n > 0) {
            if ((m * n) % 4 == 0)
                k = (int)ceil((double)m * n / 8) * 4;
            else
                k = (int)ceil((double)m * n / 4) * 2;
        }
        else
            k = (int)ceil((double)m * n / 2);

        cout << k << " knights may be placed on a "
            << m << " row "
            << n << " column board.\n";
    }
}
