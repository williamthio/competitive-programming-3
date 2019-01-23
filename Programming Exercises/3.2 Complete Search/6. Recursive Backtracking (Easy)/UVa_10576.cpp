#include <iostream>

using namespace std;

void uva_10576() {
    int s, d;
    while (cin >> s, !cin.fail()) {
        cin >> d;

        int surplus = 5;
        int deficit = 0;
        while (surplus > 0 && surplus * s >= deficit * d) {
            surplus--;
            deficit++;
        }

        int sum = 0;
        for (int i = 0; i < 12; i++)
            sum += i % 5 < surplus ? s : -d;

        if (sum < 0)
            cout << "Deficit\n";
        else
            cout << sum << "\n";
    }
}
