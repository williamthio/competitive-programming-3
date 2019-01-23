#include <iostream>

using namespace std;

void uva_11933() {
    int n;
    while (cin >> n, n) {
        int a = 0;
        int b = 0;
        int pos = 0;
        int count = 0;
        while (n) {
            if ((n & 1) != 0) {
                count++;
                if (count % 2 == 1)
                    a |= 1 << pos;
                else
                    b |= 1 << pos;
            }
            n >>= 1;
            pos++;
        }
        cout << a << " " << b << "\n";
    }
}
