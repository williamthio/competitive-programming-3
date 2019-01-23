#include <iostream>

using namespace std;

void uva_12405() {
    int tc;
    cin >> tc;
    for (int ci = 1; ci <= tc; ci++) {
        int n;
        cin >> n;

        char field[100];
        for (int i = 0; i < n; i++)
            cin >> field[i];

        int count = 0;
        for (int i = 0; i < n - 2; i++) {
            if (field[i] == '.') {
                field[i] = '#';
                field[i + 1] = '#';
                field[i + 2] = '#';
                i += 2;
                count++;
            }
        }

        if (field[n - 1] == '.' || field[n - 2] == '.')
            count++;

        cout << "Case " << ci << ": " << count << "\n";
    }
}
