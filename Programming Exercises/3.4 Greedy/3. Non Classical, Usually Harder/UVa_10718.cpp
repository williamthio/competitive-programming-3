#include <iostream>

using namespace std;

void uva_10718() {
    unsigned int n;
    while (cin >> n, !cin.fail()) {
        unsigned int l, u;
        cin >> l;
        cin >> u;

        unsigned int m = 0;
        for (int i = 31; i >= 0; i--) {
            if (n & (1 << i)) {
                if ((m | (1 << i)) > l)
                    continue;
                else
                    m |= (1 << i);
            }
            else if ((m | (1 << i)) <= u) {
                m |= (1 << i);
            }
        }

        cout << m << "\n";
    }
}
