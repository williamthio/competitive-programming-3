#include <iostream>
#include <functional>
#include <cstring>

using namespace std;

void uva_00357() {
    int types[] = { 1, 5, 10, 25, 50 };

    long long memo[5][30001];
    memset(memo, -1, sizeof memo);

    function<long long(int, int)> change = [&](int type, int money) -> long long {
        if (type == 5 || money < 0)
            return 0;
        if (money == 0)
            return 1;
        if (memo[type][money] != -1)
            return memo[type][money];

        return memo[type][money] = change(type, money - types[type]) + change(type + 1, money);
    };

    int n;
    while (cin >> n, !cin.fail()) {
        long long numWays = change(0, n);
        if (numWays == 1)
            cout << "There is only 1 way to produce " << n << " cents change.\n";
        else
            cout << "There are " << numWays << " ways to produce " << n << " cents change.\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    uva_00357();
    return 0;
}

