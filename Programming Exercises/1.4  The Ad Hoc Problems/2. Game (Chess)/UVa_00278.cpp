#include <iostream>
#include <cmath>

using namespace std;

void uva_00278() {
    int tc;
    char piece;
    int m, n;
    cin >> tc;
    while (tc--) {
        cin >> piece;
        cin >> m;
        cin >> n;
        if (piece == 'K') {
            m = m % 2 == 1 ? m + 1 : m;
            m /= 2;
            n = n % 2 == 1 ? n + 1 : n;
            n /= 2;
            cout << m * n << "\n";
        }
        else if (piece == 'k') {
            cout << ceil((double)m * n / 2) << "\n";
        }
        else {
            // Q and r
            cout << (m < n ? m : n) << "\n";
        }
    }
}
