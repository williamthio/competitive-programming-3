#include <iostream>
#include <functional>
#include <cstring>

using namespace std;

void uva_10616() {
    int set = 1;
    int n, q;
    while (cin >> n, cin >> q, n && q) {
        cout << "SET " << set++ << ":\n";

        int arr[200];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int qi = 1; qi <= q; qi++) {
            int d, m;
            cin >> d;
            cin >> m;

            int memo[200][20][10];
            memset(memo, -1, sizeof memo);

            function<int(int, int, int)> find = [&](int idx, int mod, int count) -> int {
                if (count == m)
                    return mod == 0;
                if (idx == n)
                    return 0;
                if (memo[idx][mod][count] != -1)
                    return memo[idx][mod][count];
                int newMod = (mod + arr[idx]) % d;
                if (newMod < 0)
                    newMod += d;
                return memo[idx][mod][count] = find(idx + 1, newMod, count + 1) + find(idx + 1, mod, count);
            };

            cout << "QUERY " << qi << ": " << find(0, 0, 0) << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_10616();
    return 0;
}

