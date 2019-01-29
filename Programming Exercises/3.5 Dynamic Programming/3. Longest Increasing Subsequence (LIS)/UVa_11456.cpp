#include <iostream>
#include <algorithm>

using namespace std;

void uva_11456() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        int cars[2000];
        for (int i = n - 1; i >= 0; i--)
            cin >> cars[i];

        int lis[2000], lds[2000];
        lis[0] = lds[0] = 1;
        for (int i = 1; i < n; i++) {
            int lisMax = 1;
            int ldsMax = 1;
            for (int j = 0; j < i; j++) {
                if (cars[j] < cars[i])
                    lisMax = max(lisMax, lis[j] + 1);
                else if (cars[j] > cars[i])
                    ldsMax = max(ldsMax, lds[j] + 1);
            }
            lis[i] = lisMax;
            lds[i] = ldsMax;
        }

        int optimal = 0;
        for (int i = 0; i < n; i++)
            optimal = max(optimal, lis[i] + lds[i] - 1);

        cout << optimal << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_11456();
    return 0;
}

