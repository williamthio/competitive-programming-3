#include <iostream>
#include <functional>
#include <string>
#include <cmath>

using namespace std;

void uva_12060() {
    auto gcd = [&](int a, int b) {
        int t;
        while (b != 0) {
            t = b;
            b = a % b;
            a = t;
        }
        return a;
    };

    int n, tc = 0;
    while (cin >> n, n) {
        cout << "Case " << ++tc << ":\n";

        int sum = 0;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            sum += v;
        }

        string mid = "";
        if (sum < 0)
            mid += "- ";

        sum = abs(sum);
        int quotient = sum / n;
        if (quotient > 0)
            mid += to_string(quotient);

        int remainder = sum % n;
        if (remainder == 0) {
            if (quotient == 0)
                mid += to_string(quotient);
            cout << mid << "\n";
        }
        else {
            int divisor = gcd(remainder, n);

            remainder /= divisor;
            n /= divisor;

            string numerator = to_string(remainder);
            string denominator = to_string(n);

            string top = "";
            string bottom = "";
            int mn = mid.size();
            while (mn--) {
                top += ' ';
                bottom += ' ';
            }
            int diff = denominator.size() - numerator.size();
            while (diff--)
                top += ' ';

            top += numerator;
            bottom += denominator;
            
            int dashLength = denominator.size();
            while (dashLength--)
                mid += '-';

            cout << top << "\n" << mid << "\n" << bottom << "\n";
        }
    }
}
