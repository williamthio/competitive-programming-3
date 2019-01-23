#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

void uva_00524() {
    int tc = 0;
    int n;
    while (cin >> n, !cin.fail()) {
        if (tc > 0)
            cout << "\n";
        cout << "Case " << ++tc << ":\n";

        int primes[] = { 2, 3, 5 };
        auto isPrime = [&](int num) {
            for (int p : primes) {
                if (num % p == 0) {
                    if (num == p)
                        return true;
                    return false;
                }
            }
            return true;
        };

        int ring[16];

        auto check = [&](int idx, int num) {
            if (!isPrime(ring[idx - 1] + num))
                return false;
            for (int prev = 0; prev < idx; prev++) {
                if (num == ring[prev])
                    return false;
            }
            return true;
        };

        function<void(int)> generate = [&](int idx) {
            if (idx == n && isPrime(ring[n - 1] + 1)) {
                for (int i = 0; i < n; i++) {
                    cout << (i > 0 ? " " : "") << ring[i];
                };
                cout << "\n";
            }
            else {
                for (int num = 1; num <= n; num++) {
                    if (check(idx, num)) {
                        ring[idx] = num;
                        generate(idx + 1);
                    }
                }
            }
        };

        ring[0] = 1;
        generate(1);
    }
}
