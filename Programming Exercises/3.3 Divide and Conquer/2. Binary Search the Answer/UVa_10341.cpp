#include <iostream>
#include <functional>
#include <cmath>
#include <iomanip>

using namespace std;

void uva_10341() {
    int p, q, r, s, t, u;
    while (cin >> p, !cin.fail()) {
        cin >> q;
        cin >> r;
        cin >> s;
        cin >> t;
        cin >> u;

        auto check = [&](double x) -> double {
            return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
        };

        double low = 0;
        double high = 1;
        double value = 0;
        bool valid = true;
        while (fabs(high - low) > 1e-9) {
            double mid = (low + high) / 2.0;
            value = check(mid);
            if (value > 0)
                low = mid;
            else
                high = mid;
        }

        if (fabs(value) < 1e-5)
            cout << fixed << setprecision(4) << high << "\n";
        else
            cout << "No solution\n";
    }
}
