#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <limits>

using namespace std;

void uva_10141() {
    int n, p, r, tc = 0, maxItem;
    string name;
    double price, prev, minPrice;
    bool isSame;
    vector<pair<string, double>> proposals;
    while (cin >> n, cin >> p, n && p) {
        maxItem = -1;
        proposals.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        while (n--)
            getline(cin, name);
        while (p--) {
            getline(cin, name);
            cin >> price;
            cin >> r;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (maxItem < r) {
                maxItem = r;
                proposals.clear();
                proposals.push_back(make_pair(name, price));
            }
            else if (maxItem == r) {
                proposals.push_back(make_pair(name, price));
            }
            while (r--)
                getline(cin, name);
        }
        minPrice = -1;
        prev = -1;
        isSame = true;
        for (auto it = proposals.begin(); it != proposals.end(); it++) {
            if (prev == -1) {
                prev = it->second;
                minPrice = it->second;
                name = it->first;
                continue;
            }
            if (minPrice > it->second) {
                minPrice = it->second;
                name = it->first;
            }
            isSame = it->second == prev;
            prev = it->second;
        }
        if (tc > 0)
            cout << "\n";
        cout << "RFP #" << ++tc << "\n";
        if (isSame && prev != -1)
            cout << proposals[0].first << "\n";
        else
            cout << name << "\n";
    }
}
