#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

void uva_00573() {
    int h, dp;
    double u, d, f, ch;
    while (cin >> h, h) {
        cin >> u;
        cin >> d;
        cin >> f;
        f = u * (f / 100);
        dp = 0;
        ch = 0;
        while (true) {
            dp++;
            if (u > 0)
                ch += u;
            u -= f;
            if (ch > h) {
                cout << "success";
                break;
            }
            ch -= d;
            if (ch < 0) {
                cout << "failure";
                break;
            }
        }
        cout << " on day " << dp << "\n";
    }
}
