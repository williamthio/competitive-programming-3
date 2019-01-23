#include <iostream>
#include <set>

using namespace std;

void uva_11136() {
    int n;
    while (cin >> n, n) {
        long long total = 0;
        multiset<int> urn;
        while (n--) {
            int bn;
            cin >> bn;

            while (bn--) {
                int amount;
                cin >> amount;
                urn.insert(amount);
            }

            if (urn.size() < 2)
                continue;

            total += *urn.rbegin() - *urn.begin();

            urn.erase(urn.begin());
            urn.erase(--urn.end());
        }
        cout << total << "\n";
    }
}
