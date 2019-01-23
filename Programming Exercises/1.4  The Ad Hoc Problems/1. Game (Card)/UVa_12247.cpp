#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

void uva_12247() {
    int card;
    while (cin >> card, card) {
        vector<int> princess, prince;
        princess.resize(3);
        prince.resize(2);
        princess[0] = card;
        cin >> princess[1];
        cin >> princess[2];
        cin >> prince[0];
        cin >> prince[1];

        vector<int> checker = princess;
        checker.push_back(prince[1]);
        checker.push_back(prince[0]);

        sort(princess.begin(), princess.end());
        sort(prince.begin(), prince.end());

        int lowest = -1;
        for (auto it = prince.begin(); it != prince.end(); it++) {
            int i;
            int n = princess.size();
            for (i = 0; i < n; i++) {
                if (princess[i] > *it)
                    break;
            }
            if (i < n) {
                if (i == n - 1)
                    princess.pop_back();
                else {
                    int temp = princess[i];
                    princess[i] = princess[n - 1];
                    princess[n - 1] = temp;
                    princess.pop_back();
                    sort(princess.begin(), princess.end());
                }
            }
        }
        if (princess.size() > 1) {
            int i;
            if (princess.size() == 3)
                i = 0;
            else
                i = princess.back();
            for (i += 1; i <= 52; i++) {
                bool ok = true;
                for (auto it = checker.begin(); it != checker.end(); it++) {
                    if (i == *it)
                        ok = false;
                }
                if (ok) {
                    lowest = i;
                    break;
                }
            }
        }
        cout << lowest << "\n";
    }
}
