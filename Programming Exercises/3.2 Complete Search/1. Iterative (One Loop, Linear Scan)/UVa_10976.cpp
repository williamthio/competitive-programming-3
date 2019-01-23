#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void uva_10976() {
    int k;
    while (cin >> k, !cin.fail()) {
        vector<string> output;
        for (int y = k + 1; y <= (k << 1); y++) {
            double x = (double)y * k / (y - k);
            if (x == floor(x)) {
                ostringstream oss;
                oss << "1/" << k << " = 1/" << (int)x << " + 1/" << y << "\n";
                output.push_back(oss.str());
            }
        }
        cout << output.size() << "\n";
        for (string s : output)
            cout << s;
    }
}
