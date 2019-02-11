#include <iostream>
#include <cstring>
#include <functional>

using namespace std;

void uva_10943() {
    int n, k;
    while (cin >> n, cin >> k, n || k) {
        int memo[99][101];
        memset(memo, -1, sizeof memo);

        function<int(int, int)> add = [&](int pos, int sum) -> int {
            if (pos == k - 1)
                return 1;
            if (memo[pos][sum] != -1)
                return memo[pos][sum];
            int count = 0;
            for (int i = 0; sum + i <= n; i++)
                count += add(pos + 1, sum + i);
            return memo[pos][sum] = count % 1000000;
        };

        cout << add(0, 0) << "\n";
    }
}

void uva_10943_pt() {
    int pt[200][100];
    int h = 2;
    pt[0][0] = 1;
    pt[1][0] = 1;

    function<void(int)> updatePascalTriangle = [&](int n) {
        if (h > n || n >= 200)
            return;
        for ( ; h <= n; h++) {
            if (!(h & 1))
                pt[h][h >> 1] = (pt[h - 1][(h >> 1) - 1] << 1) % 1000000;
            pt[h][0] = 1;
            for (int i = 1, len = h / 2 + (h & 1 ? 1 : 0); i < len; i++)
                pt[h][i] = (pt[h - 1][i - 1] + pt[h - 1][i]) % 1000000;
        }
    };

    int n, k;
    while (cin >> n, cin >> k, n || k) {
        k--;
        n += k;
        updatePascalTriangle(n);
        cout << pt[n][k < n - k ? k : n - k] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_10943_pt();
    return 0;
}

