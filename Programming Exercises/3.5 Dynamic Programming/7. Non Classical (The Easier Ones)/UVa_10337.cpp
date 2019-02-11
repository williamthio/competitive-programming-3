#include <iostream>
#include <cstring>
#include <functional>

using namespace std;

void uva_10337() {
    int tc;
    cin >> tc;
    while (tc--) {
        int x;
        cin >> x;
        x /= 100;

        char winds[10][1000];
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < x; j++) {
                int wind;
                cin >> wind;
                winds[i][j] = wind;
            }
        }

        int memo[10][1000];
        memset(memo, -1, sizeof memo);

        function<int(int, int)> fly = [&](int altitude, int mile) -> int {
            if (mile == x)
                return 0;
            if (memo[altitude][mile] != -1)
                return memo[altitude][mile];
            int wind = -winds[altitude][mile];
            int usedFuel = 1 << 30;
            if (altitude < 9 && altitude + 1 < x - mile)
                usedFuel = min(usedFuel, 60 + wind + fly(altitude + 1, mile + 1));
            if (altitude < x - mile)
                usedFuel = min(usedFuel, 30 + wind + fly(altitude, mile + 1));
            if (altitude > 0)
                usedFuel = min(usedFuel, 20 + wind + fly(altitude - 1, mile + 1));
            return memo[altitude][mile] = usedFuel;
        };

        cout << fly(0, 0) << "\n\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_10337();
    return 0;
}

