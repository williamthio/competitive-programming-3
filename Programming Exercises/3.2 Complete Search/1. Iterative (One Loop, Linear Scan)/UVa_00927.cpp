#include <iostream>
#include <cmath>

using namespace std;

void uva_00927() {
    int tc;
    cin >> tc;
    while (tc--) { 
        int i, c[21];
        cin >> i;
        for (int j = 0; j <= i; j++)
            cin >> c[j];

        int d, k;
        cin >> d;
        cin >> k;

        unsigned long long a;
        int sum = 0, n = 1;
        while (sum < k) {
            a = c[0];
            for (int j = 1; j <= i; j++)
                a += c[j] * (unsigned long long)pow(n, j);
            sum += n++ * d;
        }

        cout << a << "\n";
    }
}
