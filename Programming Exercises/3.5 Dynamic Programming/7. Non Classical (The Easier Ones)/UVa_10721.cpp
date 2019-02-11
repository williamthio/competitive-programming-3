#include <iostream>
#include <cstring>
#include <functional>

using namespace std;

void uva_10721() {
    int n, k, m;
    while (cin >> n, !cin.fail()) {
        cin >> k;
        cin >> m;

        long long memo[50][50];
        memset(memo, -1, sizeof memo);

        function<long long(int, int)> set = [&](int count, int group) -> long long {
            if (count == n)
                return group == k;
            if (count > n)
                return 0;
            if (memo[count][group] != -1)
                return memo[count][group];
            long long sum = 0;
            for (int i = 1; i <= m; i++)
                sum += set(count + i, group + 1);
            return memo[count][group] = sum;
        };

        cout << set(0, 0) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_10721();
    return 0;
}

