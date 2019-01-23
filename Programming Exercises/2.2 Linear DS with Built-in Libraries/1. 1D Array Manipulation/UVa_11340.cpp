#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <limits>
#include <string>

using namespace std;

void uva_11340() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        unordered_map<char, int> charPrices;
        while (n--) {
            char c;
            cin >> c;
            int price;
            cin >> price;
            charPrices[c] = price;
        }
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        int total = 0;
        while (n--) {
            string line;
            getline(cin, line);
            for (int i = 0, n = line.size(); i < n; i++)
                total += charPrices[line[i]];
        }
        cout << fixed << setprecision(2) << (total / 100.0) << "$\n";
    }
}
