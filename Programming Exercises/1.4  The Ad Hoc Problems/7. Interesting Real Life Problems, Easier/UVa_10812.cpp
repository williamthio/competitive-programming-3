#include <iostream>
#include <cmath>

using namespace std;

void uva_10812() {
    int tc;
    cin >> tc;
    while (tc--) {
        long long sum, diff;
        cin >> sum;
        cin >> diff;
        long double a = (sum + diff) / 2.0;
        long double b = (sum - diff) / 2.0;
        if (a < 0 || b < 0 || floor(a) - a != 0 || floor(b) - b != 0)
            cout << "impossible\n";
        else
            cout << (long)a << " " << (long)b << "\n";
    }
}
