#include <iostream>
#include <ctime>

using namespace std;

void uva_11683() {
    int a, c, x, count;
    while (cin >> a, a) {
        cin >> c;
        count = 0;
        while (c--) {
            cin >> x;
            if (a > x) {
                count += a - x;
            }
            a = x;
        }
        cout << count << "\n";
    }
}
