#include <iostream>
#include <iomanip>

using namespace std;

void uva_11236() {
    cout << fixed << setprecision(2);
    for (int a = 1; a < 500; a++) {
        for (int b = a; b < (2000 - a) / 3; b++) {
            for (int c = b; c < 1000 - b / 2 - a / 2; c++) {
                if (a * b * c == 1000000)
                    continue;
                int d = ((a + b + c) * 1000000 / ((a * b * c) - 1000000));
                if (d < c || d > 2000 - a - b - c)
                    continue;
                if (a * b * c * d == (a + b + c + d) * 1000000) {
                    cout << a / 100.0 << " "
                        << b / 100.0 << " "
                        << c / 100.0 << " "
                        << d / 100.0 << "\n";
                }
            }
        }
    }
}
