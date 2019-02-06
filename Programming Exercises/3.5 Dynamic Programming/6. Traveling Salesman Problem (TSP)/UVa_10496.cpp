#include <iostream>
#include <functional>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

void uva_10496() {
    int tc;
    cin >> tc;
    while (tc--) {
        int xn, yn;
        cin >> xn;
        cin >> yn;

        int beepers[11][2];
        cin >> beepers[0][0];
        cin >> beepers[0][1];

        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> beepers[i][0];
            cin >> beepers[i][1];
        }

        function<int(int, int)> length = [&](int idx1, int idx2) {
            return abs(beepers[idx1][0] - beepers[idx2][0]) + abs(beepers[idx1][1] - beepers[idx2][1]);
        };

        int memo[11][1 << 10];
        memset(memo, -1, sizeof memo);

        function<int(int, int)> move = [&](int pos, int visited) -> int {
            if (visited == (1 << n) - 1)
                return length(pos, 0);
            if (memo[pos][visited] != -1)
                return memo[pos][visited];
            int minLength = 400;
            for (int i = 1; i <= n; i++) {
                if (!(visited & (1 << (i - 1))))
                    minLength = min(minLength, length(pos, i) + move(i, visited | (1 << (i - 1))));
            }
            return memo[pos][visited] = minLength;
        };

        cout << "The shortest path has length " << move(0, 0) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_10496();
    return 0;
}

