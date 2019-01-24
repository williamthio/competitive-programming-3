#include <iostream>
#include <algorithm>

using namespace std;

void uva_10684() {
    int n;
    while (cin >> n, n) {
        int bets[10000];
        for (int i = 0; i < n; i++)
            cin >> bets[i];

        int ans = -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += bets[i];
            ans = max(ans, sum);
            if (sum < 0)
                sum = 0;
        }

        if (ans <= 0)
            cout << "Losing streak.\n";
        else
            cout << "The maximum winning streak is " << ans << ".\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_10684();
    return 0;
}

