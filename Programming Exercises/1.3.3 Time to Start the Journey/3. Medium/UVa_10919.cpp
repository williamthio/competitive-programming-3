#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void uva_10919() {
    int k, m, c, min;
    string course;
    unordered_map<string, int> taken;
    bool graduate;
    while (cin >> k, k) {
        cin >> m;
        taken.clear();
        graduate = true;
        while (k--) {
            cin >> course;
            taken[course] = 1;
        }
        while (m--) {
            cin >> c;
            cin >> min;
            while (c--) {
                cin >> course;
                min -= taken[course];
            }
            graduate = graduate && min <= 0;
        }
        cout << (graduate ? "yes" : "no") << "\n";
    }
}
