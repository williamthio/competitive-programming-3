#include <iostream>
#include <unordered_map>

using namespace std;

void uva_11849() {
    int n, m;
    while (cin >> n, cin >> m, n || m) {
        int cd;
        unordered_map<int, bool> cds;

        while (n--) {
            cin >> cd;
            cds[cd] = true;
        }

        int total = 0;
        while (m--) {
            cin >> cd;
            if (cds[cd])
                total++;
        }
        
        cout << total << "\n";
    }
}
