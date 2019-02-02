#include <iostream>
#include <functional>
#include <cstring>

using namespace std;

void uva_10306() {
    function<int(int, int)> emodulus = [&](int x, int y) {
        return x * x + y * y;
    };

    int n;
    cin >> n;
    while (n--) {
        int m, s;
        cin >> m;
        cin >> s;

        int coins[40][2];
        for (int i = 0; i < m; i++) {
            cin >> coins[i][0];
            cin >> coins[i][1];
        }

        s *= s;

        int memo[300][300];
        memset(memo, -1, sizeof(memo));

        function<int(int, int)> smallest = [&](int x, int y) {
            if (emodulus(x, y) == s)
                return 0;
            if (memo[x][y] != -1)
                return memo[x][y];
            int count = (1 << 30);
            for (int i = 0; i < m; i++) {
                if (emodulus(x + coins[i][0], y + coins[i][1]) <= s)
                    count = min(count, 1 + smallest(x + coins[i][0], y + coins[i][1]));
            }
            return memo[x][y] = count;
        };

        int count = smallest(0, 0);
        if (count == (1 << 30))
            cout << "not possible\n";
        else
            cout << count << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_10306();
    return 0;
}

