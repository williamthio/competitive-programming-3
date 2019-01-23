#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <unordered_set>

using namespace std;

void uva_01262() {
    int tc;
    cin >> tc;
    while (tc--) {
        int k;
        cin >> k;

        char first[5][6], second[5][6];
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 5; j++)
                cin >> first[j][i];
        }
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 5; j++)
                cin >> second[j][i];
        }

        for (int i = 0; i < 5; i++) {
            sort(first[i], first[i] + 6);
            sort(second[i], second[i] + 6);
        }

        unordered_set<string> passwords;
        string password = "-----";
        function<void(int)> search = [&](int idx) {
            if (passwords.size() == k)
                return;

            if (idx == 5) {
                passwords.insert(password);
                if (passwords.size() == k)
                    cout << password << "\n";
                return;
            }

            for (int i = 0; i < 6; i++) {
                if (binary_search(second[idx], second[idx] + 6, first[idx][i])) {
                    password[idx] = first[idx][i];
                    search(idx + 1);
                }
            }
        };

        search(0);

        if ((int)passwords.size() < k)
            cout << "NO\n";
    }
}
